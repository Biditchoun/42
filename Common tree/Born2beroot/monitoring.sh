echo "Architecture: $(uname -a)"
echo "Number of physical processors: $(grep -c processor /proc/cpuinfo)"
echo "Number of virtual processors: $(cat /proc/cpuinfo | grep processor | wc -l)"
echo "Memory usage: $(free -m | awk 'NR==2 {printf "%03d/%dMB (%.2f%%)", $3,$2,$3*100/$2}')"
echo "Disk usage: $(df -h | awk '$NF=="/" {printf "%.1f/%.1fGB (%s)", $3,$2,$5}')"
echo "Processors usage: $(mpstat | awk 'NR==4 {printf "%.2f%%", $6}')"
echo "Last boot: $(who -b awk '{printf "%s %s", $3,$4}')"
echo "Is LVM active ? $(if cat /etc/fstab | grep -q "/dev/mapper/"; then echo "Yes"; else echo "No"; fi)"
echo "Number of active connections: $(netstat -an | grep ESTABLISHED | wc -l)"
echo "Number of users: $(who | wc -l)"
echo "IP address: $(hostname -I)"
echo "MAC address: $(ip link show | awk '$1 == "link/ether" {print $2}')"
echo "Numner of SUDO uses: $(journalctl -q | grep sudo | grep COMMAND | wc -l)"