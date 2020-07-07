![e-yantra_logo](http://mooc.e-yantra.org/img/eYantra_logo.svg)

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
<img src="http://mooc.e-yantra.org/img/EyantraLogoMini.png" class="back" align = "center">

<center><h3>Week-1, Experiment-1</h3></center>
<center><h4>Getting started with Embedded C Programming in ATmega2560</h4></center>

---------------------------------

#### OBJECTIVE

In this experiment, you will use SPI module in  **ATmega2560** . You are provided with the skeleton code and you have to fill in the functions given, with the required logic. You are free to define your own functions too.

You will also use Masking and Shift operators in this experiment.

In this expriment you have to send numbers and see it on SPI debugger

The Program is provided as **MPLAB** project.  When you complete the functions, you have to build the project to check your solution.

-------------------------

#### SOFTWARE REQUIRED

1. MPLAB X IDE 
2. XC8, C Compile 

--------------------

#### CONNECTIONS 

* PB1 SCK
* PB2 DIN
* PB3 DOUT
* PB4 Ground

------------------------------------

#### PROCEDURE

**Step-1:**  To Open the project  the project start **MPLAB X IDE**. Click on *File* > *Open Project*,
 (OR press : Ctrl + Shift + O). Browse to the directory of the Project and click on AVR_SPI.X



**Step-2:**  The structure of the project is provided, and you have to implement necessary logic to complete
the functions. After you are finished Debug the program to check and resolve all errors.



**Step-3:** Once you are done with resolving the errors, build the project by 
*Click Production > Build Project (Experiment-N)*  OR  Simply by pressing  <F11> key

If there are no errors present in your program, the project will get compiled correctly and you will get the  message in the **Output** window as below:

```pseudocode
BUILD SUCCESSFUL (total time: 62ms)
```

**Step-4:** Now you have to check if the program you have written gives the correct output.
Load the hex file generated in the the in MIcrocontroller.

-----

* #### MACROS to use

  **`#define ddr_spi DDRB #define port_spi PORTB #define spi_control_reg SPCR #define spi_status_reg SPSR #define spi_data_reg SPDR #define spi_interrupt_flag SPIF`**

-----------------------------

#### Simulation: EXPECTED OUTPUT

SPI debugger would show value which yo send from MCU 

---------------

#### SUBMISSION INSTRUCTIONS

Upload the **AVR_SPI.X** project on the portal.