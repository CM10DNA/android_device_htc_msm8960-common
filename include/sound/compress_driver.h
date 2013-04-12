/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __COMPRESS_DRIVER_H
#define __COMPRESS_DRIVER_H
#include <linux/types.h>
#include <linux/sched.h>
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
#include <sound/compress_offload.h>
#include <sound/asound.h>
#include <sound/pcm.h>
struct snd_compr_ops;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
struct snd_compr_runtime {
 snd_pcm_state_t state;
 struct snd_compr_ops *ops;
 void *buffer;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u64 buffer_size;
 u32 fragment_size;
 u32 fragments;
 u64 hw_pointer;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 u64 app_pointer;
 u64 total_bytes_available;
 u64 total_bytes_transferred;
 wait_queue_head_t sleep;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_compr_stream {
 const char *name;
 struct snd_compr_ops *ops;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct snd_compr_runtime *runtime;
 struct snd_compr *device;
 enum snd_compr_direction direction;
 void *private_data;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_compr_ops {
 int (*open)(struct snd_compr_stream *stream);
 int (*free)(struct snd_compr_stream *stream);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int (*set_params)(struct snd_compr_stream *stream,
 struct snd_compr_params *params);
 int (*get_params)(struct snd_compr_stream *stream,
 struct snd_codec *params);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int (*trigger)(struct snd_compr_stream *stream, int cmd);
 int (*pointer)(struct snd_compr_stream *stream,
 struct snd_compr_tstamp *tstamp);
 int (*copy)(struct snd_compr_stream *stream, const char __user *buf,
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 size_t count);
 int (*mmap)(struct snd_compr_stream *stream,
 struct vm_area_struct *vma);
 int (*ack)(struct snd_compr_stream *stream, size_t bytes);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 int (*get_caps) (struct snd_compr_stream *stream,
 struct snd_compr_caps *caps);
 int (*get_codec_caps) (struct snd_compr_stream *stream,
 struct snd_compr_codec_caps *codec);
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
};
struct snd_compr {
 const char *name;
 struct device *dev;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct snd_compr_ops *ops;
 void *private_data;
 struct snd_card *card;
 unsigned int direction;
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
 struct mutex lock;
 int device;
};
#endif
/* WARNING: DO NOT EDIT, AUTO-GENERATED CODE - SEE TOP FOR INSTRUCTIONS */
