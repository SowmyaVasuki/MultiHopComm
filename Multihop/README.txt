Android App based Heterogenous Communication - A Comparison between 2-hop, 3-hop, 4-hop

3-hop:
Android app -> Bluetooth Module(on Arduino1) -> Can Sender(Arduino1) -> Can Receiver(Arduino2) -> Bluetooth Module(Arduino2) -> Android App

Arduino1: fcom_bluetooth_arduino
Arduino2 : fcom_bt_receive_arduino


4-hop:

An intermediate hop is added to the above proceedure.
Arduino1 has a rf transmitter and another arduino(NArduino2) is added
in between with the rf receiver and CAN sender.

Arduino1: btrfsend
NArduino2 : rfcansend
Arduino2 : fcom_bt_receive_arduino

Also includes Encrypion and decryption of data.