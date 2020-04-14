          The eeprom (Electrically Erasable and Programmable Read Only Memory) is a non-volatile memory often used to embed value in the microcontroller.

          Maximum write operations that can be performed on EEPROM are 10000 after which it can no longer retain the value.

          Operations that can be performed on EEPROM are:

            -EEPROM.read(addr)          -> used to read values stored in EEPROM.

            -EEPROM.write(addr, value)  -> used to store/write value in specified address

            -EEPROM.update(addr, value) -> used to write value in specified address
              The EEPROM.update function helps in reducing write operations since it eliminates the operation if value to be writeen is similar to the new value.

            -EEPROM.clear()             -> used to clear EEPROM memory.


          Remark:

                To write any value at specified location, the location needs to be set to zero using eeprom.write(0, address)