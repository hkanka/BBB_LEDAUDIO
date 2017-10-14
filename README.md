# BBB_LEDAUDIO
Audio analyzer with BeagleBone Black

BBB_LEDAUDIO is the client of PW_AudioLED https://github.com/joek85/PW_AudioLED.

it receives 65 bytes of framebuffer from udp network and displays it.
it uses two threads,one for clocking and the second is for reading from udp and filling the buffer.
the secong thread is blocked by udp,therefore it waits for udp data and then fills the buffer,if you want non-block configuration you can uncomment the commented section inside udp.c.
if you want to add more led modules,just change the WIDTH and HEIGHT and the number of the array buffer.
you can see a video about it on youtube: https://www.youtube.com/watch?v=sMVi36LVPxk

<br>
<img height="480" width="900" src="https://github.com/joek85/BBB_LEDAUDIO/blob/master/Images/Img1.jpg?raw=true" />
<br>

<br>
<img height="480" width="900" src="https://github.com/joek85/BBB_LEDAUDIO/blob/master/Images/Img2.jpg?raw=true" />
<br>

<br>
<img height="480" width="900" src="https://github.com/joek85/BBB_LEDAUDIO/blob/master/Images/Img3.jpg?raw=true" />
<br>

<br>
<img height="480" width="900" src="https://github.com/joek85/BBB_LEDAUDIO/blob/master/Images/Img4.jpg?raw=true" />
<br>
