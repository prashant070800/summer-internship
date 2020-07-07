![e-yantra_logo](http://mooc.e-yantra.org/img/eYantra_logo.sv

<style>
.back{
	position: fixed;
	width: 300px;
	height: 300px;
	top: 50%;
	left: 40%;
    margin-top: auto; 
    margin-left: auto; 
	opacity: 0.15;
	}
</style>
<img src="http://mooc.e-yantra.org/img/EyantraLogoMini.png" class="back">

<center><h3>Week-1, Experiment</h3></center>
<center><h4>Getting started with Embedded C Programming in PIC</h4></center>

--------------

#### AIM

In this experiment, you will use I2C module in **ATmega2560**.  You are provided with a skeleton code of UART interfacing program and you have to fill the functions with the required logic. You have been given lcd functions in your service. You are free to define your own functions too.

The program is provided as **MPLABX IDE** project. When you complete the functions, you have to build the project to check your solution.

-----------------------------------------------------------------------------------------------------

#### SOFTWARE REQUIRED

1. MPLAB X IDE 
2. XC8, C Compiler. 

--------------------

#### CONNECTIONS

* SDA Pin  :    pin 44, (PD1)
* SCL Pin  :    pin 43 , (PD0)

-----------------

#### PROCEDURE

**Step-1:** To Open the project  the project start **MPLAB X IDE**. Click on *File* > *Open Project*,
 (OR press : Ctrl + Shift + O). Browse to the directory of the Project and click on **AVR_I2C**



**Step-2:** The structure of the project is provided, and you have to implement necessary logic to complete the functions. After you are finished Debug the program to check and resolve all errors.



**Step-3:** Once you are done with resolving the errors, build the project by  *Click Production > Build Project (Experiment-N)*  OR  Simply by pressing  <F11> key.



**Step-4:** Once you are done with resolving the errors, build the project using the shortcut key **Ctrl+Alt+F7** or from the Menu bar: _Build > Rebuild solution_.

If there are no errors present in your program, the project will get compiled correctly and you will get the  message in the **Output** window as below:

```pseudocode
BUILD SUCCESSFUL (total time: 62ms)
```



**Step-5:** Now you have to check if the program you have written gives the correct output.
Load the hex file generated into the sample of Proteus Demo and simulate the output.

-----

#### MACROS to use

- Constants are defined as follows:

  **`#define EEPROM_Write_Addess 0xA0 #define TWI_data_reg TWDR #define TWI_control_reg TWCR #define TWI_status_reg TWSR #define TWI_bit_rate_reg TWBR`**
  
  

----------------

#### Simulation: EXPECTED OUTPUT

​	**Software required:** Proteus

  I2C debugger would show value which yo send from MCU   

---------------

#### SUBMISSION INSTRUCTIONS

Upload the **AVR_I2C.X** file on the portal.
