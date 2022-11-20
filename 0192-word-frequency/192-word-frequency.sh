grep -Eio "\w+" words.txt | sort | uniq -c | sort -r | awk '{print $2, $1}'
