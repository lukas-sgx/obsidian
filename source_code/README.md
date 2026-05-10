# G-SEC-210 Project: Obsidian Console

## Project Overview
The **Obsidian Console** is a command-line interface (CLI) designed to simulate the operation and management of a nuclear reactor. This project is part of the G-SEC-210 module and focuses on secure software development practices, including vulnerability identification, mitigation, and secure coding techniques.

The console provides a variety of commands to interact with the reactor's systems, monitor its status, and simulate emergency scenarios. It also includes hidden features and challenges to test the user's ability to identify and secure potential vulnerabilities.

---

## Features
- **Reactor Initialization**: Safely start the reactor and prepare it for operation.
- **Status Monitoring**: Check the reactor's core temperature, coolant flow rate, and radiation levels.
- **Emergency Protocols**: Activate emergency shutdowns and simulate meltdown scenarios.
- **System Diagnostics**: Run diagnostics and monitor critical system parameters.
- **Configuration Management**: Load and configure reactor settings.
- **Hidden Features**: Includes secret commands for advanced users.
- **And even more!**

---

## Commands
Below is a list of available commands in the Obsidian Console:

| Command                     | Description                                                                 |
|-----------------------------|-----------------------------------------------------------------------------|
| `init_reactor`              | Initialize the reactor for operation.                                      |
| `check_reactor_status`      | Check the current status of the reactor.                                   |
| `activate_emergency_protocols` | Activate emergency protocols (requires admin privileges).                |
| `simulate_meltdown`         | Simulate a reactor meltdown for testing purposes.                          |
| `check_cooling_pressure`    | Check the pressure in the cooling system.                                  |
| `send_status_report`        | Send a status report to the control center.                                |
| `monitor_radiation_levels`  | Monitor radiation levels in the reactor.                                   |
| `set_reactor_power`         | Adjust the reactor's power output.                                         |
| `run_diagnostic`            | Run a full diagnostic on the reactor systems.                              |
| `enable_remote_access`      | Enable or disable remote access to the reactor.                            |
| `load_fuel_rods`            | Load fuel rods into the reactor.                                           |
| `log_system_event`          | Log a system event.                                                        |
| `load_config`               | Load configuration from a file.                                            |
| `configure_cooling_system`  | Configure the cooling system.                                              |
| `init_steam_turbine`        | Initialize the steam turbine.                                              |
| `read_turbine_config`       | Read the turbine configuration.                                            |
| `turbine_remote_access`     | Remote access to the turbine.                                              |
| `run_turbine`               | Run the turbine.                                                           |
| `turbine_temperature`       | Change the turbine temperature.                                            |
| `history`                   | Display a list of all the commands that have been typed.                   |
| `quit`                      | Exit the console.                                                          |
| `help`                      | Display a list of available commands.                                      |

---

## How to Run
   ```bash
$> export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
$> make
$> ./obsidian
   ```

---

## Contributors
We would like to thank the following contributors for their efforts in developing and testing the Obsidian Console:

- Igoatyouu - Security Analyst
- ManuelR-T - Vulnerability Researcher
- theocampos - Creator of obsidian library
- Exeloo - Dev Ops Specialist
- Aluxray - QA Engineer

If you would like to contribute to this project, feel free to submit a pull request or contact us via the repository's issue tracker.

---

## License
This project is licensed under the MIT License.

---

## Disclaimer
This project is for educational purposes only. It is not intended for use in real-world nuclear reactor systems.
