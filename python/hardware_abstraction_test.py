import unittest
import hardware_abstraction

class HardwareAbstractionTest(unittest.TestCase):
    def setUp(self):
        pass

    def assertSerialWorks(self, serial_connection):
        serial_pair = serial_connection.MakePair()
        self.assertEqual(serial_connection.read(), '')
        self.assertEqual(serial_pair.read(), '')
        serial_connection.write('z')
        self.assertEqual(serial_connection.read(), '')
        self.assertEqual(serial_pair.read(), 'z')
        self.assertEqual(serial_pair.read(), '')
        serial_pair.write('y')
        self.assertEqual(serial_pair.read(), '')
        self.assertEqual(serial_connection.read(), 'y')
        self.assertEqual(serial_connection.read(), '')

    def test_queue_serial(self):
        queue_serial = hardware_abstraction.QueueSerialConnection('ha_test', 9600)
        self.assertSerialWorks(queue_serial)

    def test_file_serial(self):
        file_serial = hardware_abstraction.FileSerialConnection('ha_test', 9600)
        self.assertSerialWorks(file_serial)

if __name__ == '__main__':
        unittest.main()
