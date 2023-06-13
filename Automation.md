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

## JSON code:

```js
[
    {
        "id": "dbf60ee897e493b5",
        "type": "tab",
        "label": "Flow 1",
        "disabled": false,
        "info": "",
        "env": []
    },
    {
        "id": "bf2d2628be97ecfc",
        "type": "function",
        "z": "dbf60ee897e493b5",
        "name": "function 1",
        "func": "try {\n\n/*  var SpotifyWebAPI = global.get('SpotifyWebApi')\n\n  const spotifyApi = new SpotifyWebAPI({\n      clientId: 'e0f1085127534e2d9ea9746979e4975e',\n      clientSecret: '799258594b054a05aee415d4415c575b',\n      redirectUri: 'http://localhost:1880/spotify-credentials/auth/callback',\n      scope: 'user-top-read'\n  });*/\n\n  msg.payload = \"OK this should not show up\"\n\n  // Retrieve an access token\n  let data = await spotifyApi.clientCredentialsGrant();\n  spotifyApi.setAccessToken(data.body['access_token']);\n  //console.log(data)\n  \n  let result = await spotifyApi.getMyTopTracks(); \n  msg.payload = result;\n}\ncatch (err) {\n  msg.payload = err.message + err.statusCode;\n}\n// let trackData = await spotifyApi.getMyTopTracks({time_range:'medium_term',\n//  limit: 1, offset: 0})\n// //let topTracks = trackData.body.tracks;\n// msg.payload = trackData;//topTracks\nreturn msg;",
        "outputs": 1,
        "noerr": 3,
        "initialize": "",
        "finalize": "",
        "libs": [],
        "x": 340,
        "y": 140,
        "wires": [
            [
                "39920d25547f2bfe"
            ]
        ]
    },
    {
        "id": "39920d25547f2bfe",
        "type": "debug",
        "z": "dbf60ee897e493b5",
        "name": "debug 2",
        "active": true,
        "tosidebar": true,
        "console": false,
        "tostatus": false,
        "complete": "payload",
        "targetType": "msg",
        "statusVal": "",
        "statusType": "auto",
        "x": 900,
        "y": 140,
        "wires": []
    },
    {
        "id": "898be3a0118cf46e",
        "type": "inject",
        "z": "dbf60ee897e493b5",
        "name": "",
        "props": [
            {
                "p": "payload"
            },
            {
                "p": "topic",
                "vt": "str"
            }
        ],
        "repeat": "",
        "crontab": "",
        "once": false,
        "onceDelay": 0.1,
        "topic": "",
        "payload": "",
        "payloadType": "date",
        "x": 120,
        "y": 140,
        "wires": [
            [
                "bf2d2628be97ecfc"
            ]
        ]
    },
    {
        "id": "253aba121ec8d677",
        "type": "http request",
        "z": "dbf60ee897e493b5",
        "name": "",
        "method": "GET",
        "ret": "txt",
        "paytoqs": "body",
        "url": "https://api.spotify.com/v1/me/top/tracks",
        "tls": "",
        "persist": false,
        "proxy": "",
        "insecureHTTPParser": false,
        "authType": "",
        "senderr": false,
        "headers": [
            {
                "keyType": "other",
                "keyValue": "Authorization",
                "valueType": "other",
                "valueValue": "'Bearer BQDL2iGrScj_tFbxRwbFs_HxywM0QvaykOlULxWtoBompZS2D46lmPSgAQeyvi_oHxMk73cIYIjf-rdSXm8aueibaZJx8vFTaBLH8QBgMQ4yy3Zorg4'"
            }
        ],
        "x": 610,
        "y": 220,
        "wires": [
            []
        ]
    }
]
```
