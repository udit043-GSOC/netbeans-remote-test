g++ -H -fno-exceptions -Wno-unused-function -Wno-unused-parameter -Wno-unused-variable -Wsign-promo \
-g2 -fPIC -MD -Wall -Wextra -Werror -Warray-bounds -Wbuiltin-macro-redefined -Wcast-align -Wconversion \
-Wdeprecated -Wdiv-by-zero -Wenum-compare -Wfloat-equal -Wformat-security -Wformat-y2k -Winit-self -Wlogical-op \
-Wmissing-include-dirs -Wno-format -Woverflow -Woverlength-strings -Wparentheses -Wreturn-type -Wshadow -Wsign-compare \
-Wswitch -Wtype-limits -g2 \
-DLINUX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE -D_REENTRANT -D_XOPEN_SOURCE=600 \
-DARCH=amd64 \
-I./stlport/stlport \
-D_STLP_USE_OWN_NAMESPACE -D_STLP_STD_NAME=ewoc_stlp -D_STLP_NO_IOSTREAMS -D_STLP_NO_EXCEPTIONS \
sample.cpp -o sample

