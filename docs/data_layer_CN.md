# 数据层说明文档

数据层作为帧的发送和接收中转站，定义了一个大小为 10 的 `s_entries` 数组。每个 entry 包括 `seq`、`is_seq_based`、`cmd_set`、`cmd_id` 和 `parse_result` 等字段，并配备了 LRU 和定时删除两种机制，以确保数据层在有限的空间内始终可用。

数据层提供了两种数据读写接口：`data_write_with_response` 和 `data_write_without_response`。

当调用 `data_write_with_response` 时，会分配一个 entry 用于接收解析结果，然后需要调用 `data_wait_for_result_by_seq` 来获取结果。

为什么需要定义 `data_wait_for_result_by_cmd`？有一种情况：在 `connect_logic` 中，当相机连接时，可能会主动发送命令帧给遥控器，此时 `seq` 不是我们定义的，因此需要通过 `CmdSet` 和 `CmdID` 来获取解析结果。

此外，还定义了 `receive_camera_notify_handler` 函数，这是 BLE 层调用的回调函数，用于处理相机发送的命令。

更多细节请参阅 `data.c` 源代码。

