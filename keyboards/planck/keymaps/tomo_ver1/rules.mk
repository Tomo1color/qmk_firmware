AUDIO_ENABLE = no           # Audio output on port C6
ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
