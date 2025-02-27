# Data Layer Documentation

The data layer acts as an intermediary for sending and receiving frames and defines an array `s_entries` with a size of 10. Each entry includes fields such as `seq`, `is_seq_based`, `cmd_set`, `cmd_id`, and `parse_result`. It also implements two mechanisms for removal: LRU and timed deletion, ensuring that the data layer remains available within limited space.

The data layer provides two data read/write interfaces: `data_write_with_response` and `data_write_without_response`.

When calling `data_write_with_response`, an entry is allocated to receive the parsed result, and then `data_wait_for_result_by_seq` must be called to retrieve the result.

Why is `data_wait_for_result_by_cmd` necessary? In some cases, such as in `connect_logic`, when the camera is connected, it may actively send a command frame to the remote control. At this point, `seq` is not defined by us, so the result must be retrieved using `CmdSet` and `CmdID`.

Additionally, the `receive_camera_notify_handler` function is defined as a callback function called by the BLE layer to process commands sent by the camera.

For more details, please refer to the `data.c` source code.