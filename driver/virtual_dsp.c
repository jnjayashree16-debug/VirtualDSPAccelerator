#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include "../include/vdsp/driver_uapi.h"

static long vdsp_ioctl(struct file *f,unsigned int cmd,unsigned long arg)
{
 struct vdsp_fir_request r;
 unsigned int i,k;
 if(cmd!=VDSP_IOCTL_FIR)return -ENOTTY;
 if(copy_from_user(&r,(void __user *)arg,sizeof(r)))return -EFAULT;
 if(r.input_len>VDSP_MAX_DRIVER_SAMPLES||r.coeff_len>VDSP_MAX_DRIVER_TAPS)return -EINVAL;
 for(i=0;i<r.input_len;i++){
  long long sum=0;
  for(k=0;k<r.coeff_len;k++) if(i>=k) sum+=(long long)r.input[i-k]*r.coeff[k];
  r.output[i]=(int)sum;
 }
 if(copy_to_user((void __user *)arg,&r,sizeof(r)))return -EFAULT;
 return 0;
}
static const struct file_operations fops={.owner=THIS_MODULE,.unlocked_ioctl=vdsp_ioctl};
static struct miscdevice dev={.minor=MISC_DYNAMIC_MINOR,.name="virtual_dsp",.fops=&fops,.mode=0666};
static int __init vdsp_init(void){return misc_register(&dev);}
static void __exit vdsp_exit(void){misc_deregister(&dev);}
module_init(vdsp_init);module_exit(vdsp_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Virtual DSP Accelerator Linux character device");
