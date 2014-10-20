Pkt2Flow
========

Convert Packets to Flows (in OpenFlow)

sudo tcpdump -i ethX -ennv -s 102 'ip and not arp and port not 53 and not broadcast and not multicast' -w raw_file

sudo tcpdump -ennttttv -r raw_file | awk 'BEGIN {LINE=NR;} {if($1~/2014-/) {print $1 " " $2 " " $3 " " $5 " " $22 " " $23 " ";LINE=NR;}} NR==LINE+1 {print $1 " " $3 " " $NF;}' > filtered_file

$ g++ -O3 XXX.cpp -o flow  
$ ./flow  
