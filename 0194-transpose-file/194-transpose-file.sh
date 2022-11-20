for i in $(seq $(head -n 1 file.txt | wc -w)); do echo $(cut -d' ' -f$i file.txt); done
