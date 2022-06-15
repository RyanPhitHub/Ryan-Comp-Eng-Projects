## **Journey to Lightsaber**

### Day 1: May. 26, 2022
Mr. Lam gave me 2 new beepers/speakers, and an accelerometer. I'm happy with how the new speaker sounds, but I noticed that the sound of the speaker is heavily muted if you cover the top- I'll have to design the hilt so the speakers are open-faced on the surface. I won't be soldering on the accelerometer yet though, since Mr. Lam wants to add ports so that I can just plug the new components in without committing to a solder. In the future, I should be more gentle while stripping wires.
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Progress:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - desoldered old beeper and removed it from my UBMP4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - soldered wires onto the new speaker and then soldered it onto my UBMP4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - tested the sound of the new speaker with my [blaster code](https://github.com/RyanPhitHub/Ryan-Comp-Eng-Projects/blob/706510888d710a99c2e0921ca4e99c50fcff2e93/Loop-Blaster.md)
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Setbacks and Concerns:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - after soldering the new speaker to the board, [one of the wires snapped :,(](https://user-images.githubusercontent.com/99211784/170848646-4abf5f6e-219c-436b-b169-4499ec502a3a.JPG) , but I'm hoping   
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; that's just a bad wire or I damaged it while stripping it  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - my hands have been really shakey recently, I might have to see a doctor since soldering may become dangerous  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - I'm having trouble understanding which pins I need to solder on my accelerometer; I'm using [this document](https://www.analog.com/media/en/technical-documentation/data-sheets/ADXL345.pdf) for reference but I feel  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; like the engineer and physics vocubulary is way too high level and I'm going nowhere with it   

<img src="https://user-images.githubusercontent.com/99211784/170848646-4abf5f6e-219c-436b-b169-4499ec502a3a.JPG" width="100" /> <img src="https://user-images.githubusercontent.com/99211784/170848730-1a4034b7-1c10-4520-b986-54b836b943e4.JPG" width="100" />

### Day 2: June. 1, 2022  
I've been spending the last few days trying to understand the source code for programming the ADXL345. At first, I was reading through [this code](https://github.com/kaanakgundogdu/adxl345-pic18f4550/blob/master/main.c) that **Mr. Lam** gave me, but turns out it was for the wrong chip 🤦. Anyways, so I'm using [this source code](https://www.electro-tech-online.com/threads/adxl345-accelerometer-and-18f4550-in-hi-tech-c.140017/) now, which isn't even for the exact chip but like it's close enough so we pray. A lot of the code had to do with utilizing an LCD which I wasn't using, but it ended up making the code very hard to read and organize. I'm mostly refreshed on how the wires in a breadboard work, so testing should become much easier. I've settled on wiring my accelerometer in I<sup>2</sup>C mode- though, I didn't really have a choice because the source code was made for that mode.
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Progress:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - I've hooked up all the wires via breadboard to start testing my accelerometer with the UBMP4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - After deleting chunks, moving functions and loops around, and getting Mr. Lam to help me with the many errors, I managed to 
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; successfully download new code into my UBMP4
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Setbacks and Concerns:
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - I've set up a test program where the lights will display the average acceleration on the x-axis, however none of the lights are turning  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; on, meaning the accelerometer isn't reading anything  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - I'm not sure whether the accelerometer not sending a reading is due to me wiring wrong- maybe the resisters are too high and I'm  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; not getting enough current through, or if it has to due with the source code being incompatible with my chip (the code is for a  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [PIC16F628A](https://www.alldatasheet.com/view.jsp?Searchword=Pic16f628a%20datasheet&gclid=Cj0KCQjwnNyUBhCZARIsAI9AYlFdjTxLohPIH0l4tM570dCIUa3Gejd3cUhEcAqv5xmyo7Jl7S9FhbUaAvfwEALw_wcB) while I have the [PIC16F1459](http://ww1.microchip.com/downloads/en/devicedoc/40001639b.pdf))  

<img src="https://user-images.githubusercontent.com/99211784/171536980-f597f673-ac48-41a4-98dd-20bfa1ad599e.JPG" width="100" />

### Day 3: June. 3, 2022  
So, I don't have much progress to show recently; I've been mainly just testing different things in hopes of being able to get this accelerometer to work. I initially modified the [source code](https://www.electro-tech-online.com/threads/adxl345-accelerometer-and-18f4550-in-hi-tech-c.140017/) way too much- changing the data type of the x, y, z coodinates from div_t into chars, changing function parameter types as well. I did it since I didn't want to work with complex data types, and I thought I needed to make my own div function for the div_t to work, too. Overall, that code was completely busted. Mr. Lam did end up sending me his own version of that source code though, since as it turns out, there was a div function pre-made, but i just didn't include it in my main code. I'm also testing out wiring the CS and DO pins to my board as well, since I<sup>2</sup>C mode calls for it. I intially didn't do this since I assumed that the 5V and 0V pins were the equivalent of those pins. I might end up working on getting the LEDs and speakers on first if I can't get the accelerometer to work soon.
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Progress:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - The code is mostly working now, since I measured the voltage of the data and clock pins, and can see their pulses  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - I soldered on pins to my UBMP4, which makes the wires much more stable and much easier to work with
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Setbacks and Concerns:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - After setting up an error flag for the CHIP_Read and CHIP_write, I traced an error back to the E_Write function not returning a 1  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - My LEDs sometimes flicker, and I'm worried that maybe a wire is damaged and I'm not getting stable current

### Day 4: June. 14, 2022  
Well.... its been a while since I've updated this journal, but that doesn't mean I was slacking off and made no progress! Well actually, I technically haven't made progress. I've been really stressed about the lack of progress, that I've neglected updating this in hopes I could get more done. Basically, the accelerometer is just taking may too much time out of my building process, so I'm retiring it for now. Instead I've been working on the speaker code and neopixel LEDs. The speakers are meant to play the lightsaber sounds, which I make by stringing together a bunch of notes. In order to create these notes, I find the period of each notes and convert them from seconds to cycles. However since the computer has to run through multiple cycles to read the code, I have to divide that value by a factor in order to land on the right note. I used an LCD- with [this code](https://github.com/RyanPhitHub/UBMP4-Morse-Code/blob/main/UBMP4-Intro-1-Input-Output.X/lcd.h) to display the value of the factor, and just adjusted until I got a value somewhat close, and then linearly increased it to get closer. I still haven't found the right values, but it's within a close enough range for making lightsaber sounds. I got rid of the LCD and then soldered some LEDs, and used [this tutorial and code](http://www.friendlywire.com/tutorials/ws2812/)- only after frying 2 of them somehow. Well, 1 of them was because I switched the power and ground wires. I still have to solder on more, and then figure out how to make multiple light up at once.  
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Progress:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Confirmed that speakers and LEDs are functional together- I've wired and coded both at the same time  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Created a new function to play 2 notes at once for my speakers  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Learned how to make LEDs change to different colours  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Learned how to make an LCD display a string (wasn't useful for the final project but helped with the sound code)  
#### &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; Setbacks and Concerns:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - I haven't created a battery pack that holds 2 batteries in parallel yet, and I have no idea how  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Worried about how to get the accelerometer working, since the code doesn't work, and it even impedes on my speaker code  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; - Since there's going to be multiple LEDs wired together, I'm worried about how durable those wires will be  

<img src="https://user-images.githubusercontent.com/99211784/173716464-bf4949cd-7022-4c35-95be-df82bb7fade5.JPG" width="100" /> <img src="https://user-images.githubusercontent.com/99211784/173716618-a5181b4c-918c-43e3-91f1-db69aa5025b3.JPG" width="100" />

