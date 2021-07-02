mkdir /tmp/tmpfs
mount -t tmpfs -o size=2G none /tmp/tmpfs/
dd if=/dev/zero of=/tmp/tmpfs/testfile bs=1G count=1
# 这种cache不会被释放
echo 3 > /proc/sys/vm/drop_caches 
