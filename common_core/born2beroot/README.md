# About the Born2beRoot Project

## Summary
For this project you have to create a virtual machine and set up an operating system following specific rules and configurations.

## Useful Stuff
- [Book about UNIX and Linux System Administration](https://www.amazon.com/UNIX-Linux-System-Administration-Handbook/dp/0134277554)

## Mandatory Part

- Create your first virtual machine using VirtualBox or UTM.
- Choose either the latest stable version of Debian or the latest stable version of Rocky.
- Create at least 2 encrypted partitions using LVM.
- Set up:
  - AppArmor (for Debian) or SELinux (for Rocky)
  - UFW (for Debian) or firewalld (for Rocky)
  - SSH
- Close all ports except 4242 (for the ssh connection).
- Disable SSH root login.
- Create a user and a group.
- Assign user to a group.
- Change the hostname.
- Set up a password policy
   - Password expires every 30 days.
   - Minimum 2 days before a password can be changed.
   - Warning message 7 days before password expiration.
   - Password must be at least 10 characters long, containing an uppercase letter, a lowercase letter, and a number, with no more than 3 consecutive identical characters.
   - Password must not include the user's name.
   - The password must have at least 7 characters that are not part of the former password.
   - Enforce the policy for the root user.
- Limit authentication attempts to 3.
- Display a custom error message on wrong password.
- Log all sudo actions to `/var/log/sudo/`.
- Enable TTY mode.
- Restrict paths used by sudo.
- Create a `monitoring.sh` script that displays the following information on all terminals every 10 minutes:
	- OS architecture and kernel version.
	- Number of physical and virtual processors.
	- Available RAM and usage percentage.
	- Available disk space and usage percentage.
	- CPU usage percentage.
	- Last reboot date and time.
	- LVM status.
	- Number of active connections.
	- Number of logged-in users.
	- Server's IPv4 address and MAC address.
	- Number of commands executed with sudo.
- Create a `signature.txt` file containing the signature of your machine’s virtual disk.

