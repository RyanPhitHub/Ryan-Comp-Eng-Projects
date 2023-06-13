### Overview:  
#### Using Node-Red, create an automated work flow to do something cool.

#### My Idea:  

> - Use spotify api to read my top tracks, taking the name of the song  
> - Search the song on youtube, and save the URL  
> - Using the URL, convert and download the video to MP3
> - Turn the MP3 into my ringtone
> - Update my ringtone whenever my top tracks change

### Issues:

> - Permission issues with Node-Red being able to access my phone to change the ringtone- maybe the mobile app could fix it but I haven't been able to try yet
> - Spotify API node is really outdated- I've installed my own node that's only a few years old
> - Spotify API wasn't detecting an access token
> - Method to authorize and get an an access token didn't include the necassary scopes to use my desired functions  
> - Have no idea how to generate an authorization code

### Learnings:

> - Learned how to generate an access token on spotify's API
> - Created my first Spotify app
> - Gaining a better understanding of how workflows can use APIs to create things like bots on Discord
> - Writing and using some features of Spotify's API- still can't figure out how to request my own track data
> - Gained further insight on how I should tackle my problems- looking into the error messages, specific fields, etc.
> - Formatting and using http request nodes for post and get requests
> - Learning to take advantage of the debugg node

### FInal thoughts:

#### This is one of the projects I'm more frustrated about, since it feels the most like I've reached a dead end. I need to improve my ability to dive deeper and comprehend what it is that isn't working in my program. I hate that I wasn't able to get past the first step and just get a name of my top track. However, I'm happy that I finally had an assignment where I didn't compromise my project for the sake of getting it done- I'm happy I stuck with my idea to the end, even if the chances of me pulling it off were sad at best.
