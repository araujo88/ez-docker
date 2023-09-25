# ez-docker

This project is a minimalistic example demonstrating the basics of containerization using Linux namespaces, written in C. It creates an isolated environment for running processes, similar to Docker containers. This is intended for educational purposes and to understand the underpinnings of containers.

## Features

- Process isolation using PID namespaces.
- Executing commands in the isolated environment.

## Prerequisites

- A Linux system with support for namespaces (Kernel 3.8 or later recommended).
- GCC for compiling the C program.
- Superuser access to run the program.

## Installation and Running

1. Clone the repo:
   ```sh
   git clone https://github.com/araujo88/ez-docker.git
   cd ez-docker
   ```

2. Compile the program:
   ```sh
   gcc -o ez-docker main.c -l:librt.so.1
   ```

3. Run the program as a superuser:
   ```sh
   sudo ./ez-docker "your_command"
   ```

## Usage Example

To run the `ls /` command in an isolated environment, execute:

```sh
sudo ./ez-docker "ls /"
```

## TODOs

### 1. **Incorporate Additional Namespaces**
   - Integrate Network, Mount, User, UTS, IPC, and Cgroup namespaces for comprehensive isolation.

### 2. **Implement Control Groups (cgroups)**
   - Integrate cgroups to impose resource limits such as CPU, memory, and block I/O usage.

### 3. **Filesystem Isolation**
   - Implement `chroot` or `pivot_root` to isolate the filesystem.
   - Investigate and implement an Overlay Filesystem for layered storage.

### 4. **Enhanced Networking**
   - Develop networking setups including creating virtual network interfaces, IP assignments, and routing.

### 5. **Security Enhancements**
   - Explore and apply capabilities, seccomp, AppArmor/SELinux profiles for enhanced security.

### 6. **User Interface**
   - Create a user-friendly interface or command-line tool for user inputs and interactions.

## Contribution

Contributions are welcome! Please feel free to submit a Pull Request or open an Issue for any enhancements, bug fixes, or features you think would be beneficial.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Disclaimer

This project is a simplified, educational prototype and does not have the full functionality, security, and robustness of a production-grade containerization tool like Docker. Use it at your own risk and discretion.

## Acknowledgements

- Linux Man Pages for [clone(2)](https://man7.org/linux/man-pages/man2/clone.2.html), [namespaces(7)](https://man7.org/linux/man-pages/man7/namespaces.7.html), [cgroups(7)](https://man7.org/linux/man-pages/man7/cgroups.7.html), etc.
- [Docker](https://www.docker.com/): For revolutionizing containerization.
