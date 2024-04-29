#!/bin/bash

mem_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
mem_used=$(free --mega | awk '$1 == "Mem:" {print $3}')
mem_percentage=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
disk_total=$(df -BG | awk '/^\/dev/ && !/\/boot$/ {ft += $2} END {print ft}')
disk_used=$(df -BM | awk '/^\/dev/ && !/\/boot$/ {ft += $3} END {print ft}')
disk_percentage=$(df -BM | awk '/^\/dev/ && !/\/boot$/ {ut+=$3; ft+=$2} END {printf("%d", ut/ft*100)}')

wall "	#Architecture: $(uname -a)
	#CPU physical : $(grep -c "physical id" /proc/cpuinfo)
	#vCPU : $(grep -c "^processor" /proc/cpuinfo)
	#Memory Usage: $mem_used/${mem_total}MB ($mem_percentage%)
	#Disk Usage: $disk_used/${disk_total}Gb ($disk_percentage%)
	#CPU load: $(top -bn1 | awk '/^%Cpu/ {printf("%.1f%%", $2 + $4)}')
	#Last boot: $(who -b | awk '$1 == "system" {print $3, $4}')
	#LVM use: $(lsblk | grep -q "lvm" && echo "yes" || echo "no")
	#Connections TCP : $(ss -neopt state established | wc -l) ESTABLISHED
	#User log: $(users | wc -w)
	#Network: IP $(hostname -I)($(ip link show | awk '/ether/ {print $2}'))
	#Sudo : $(grep -c COMMAND /var/log/sudo/sudo.log) cmd"
