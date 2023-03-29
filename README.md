# OGS Engine Software Development Kit

## Overview

This is a custom GPL-licensed version of the Half-Life SDK for [OGS](https://gitlab.com/BlackPhrase/OGS) and [OGSNext](https://gitlab.com/BlackPhrase/OGSNext) game engines. 
It provides you all the required license-compatible SDK components (like engine headers and utility libraries) for your game/mod development when used in pair with [openlambda](https://gitlab.com/BlackPhrase/openlambda)

## Contributing

You're not obligated to do that, but if want to help the project, feel free to contribute. All contributions are welcome and even the slightest 
help will be appreciated. Pull/Merge Requests which brings new code and documentation are especially appreciated, but you also can help by reporting about the issues you've found. The actual list of the issues can be found [here](https://gitlab.com/BlackPhrase/ogs-sdk/-/issues). You can post any 
issue regarding the project you've discovered there (things that don't work properly (or at all) or something that needs an adjustment/improvements in your opinion)

And here's how you can help improving the project:

* Fork the repo
* Get familiar with the development workflow, [Coding Guidelines](), [Code of Conduct](CODE_OF_CONDUCT.md) and learn how to sign your work
* Find an issue to work on, deal with it and submit a [Pull/Merge Request](https://gitlab.com/BlackPhrase/ogs-sdk/-/merge_requests/new)
	* First time contributing to open source? Pick [a good first issue](https://gitlab.com/BlackPhrase/ogs-sdk/-/issues?label_name%5B%5D=good+first+issue) to get you familiar with the contributing process
	* First time contributing to the project? Pick [a beginner friendly issue](https://gitlab.com/BlackPhrase/ogs-sdk/-/issues?label_name%5B%5D=beginners) to get you familiar with the codebase and our contributing process
	* Want to become a committer? Solve an issue showing that you understand the project's objectives and architecture. Here is [a good list to start](https://gitlab.com/BlackPhrase/ogs-sdk/-/issues?label_name%5B%5D=help+wanted)
* Could not find an issue? Look for bugs, typos, and missing features in the codebase and let others know about that or try to fix by yourself

### Cans and Cant's

* You CAN incorporate a piece of original [HLSDK](https://github.com/ValveSoftware/halflife) code by rewriting (retyping it line-by-line, symbol-by-symbol) it, but you CAN'T just copy-paste something from 
the there into here. The [HLSDK license](https://github.com/ValveSoftware/halflife/blob/master/LICENSE) is incompatible with [GPLv3](LICENSE) and that will be a major roadblock for you in case you will decide
to publish your mod/game on Steam, for example
* You CAN incorporate your own code pieces (the pieces you're have authored, i.e. those that you've written yourself) into the codebase and from that time they 
will be covered under the [GPLv3](LICENSE) terms
* You CAN use any game logic sources from the original Quake/Quake 2/Quake 3 and Doom 3 codebases (or any other suitable sources with compatible licenses) to improve the project's or in order to implement a missing feature
* You CAN use the SDK codebase to create a new mod or even a completely new game with it (you're also not limited by the legacy engine limits in such case) which will be running on either OGS or OGSNext engines
* You CAN expect to be mentioned as a contributor inside the source files and other files/parts you've contributed to
* You CAN expect to get help with your issues regarding the project but only if you've followed the rules and guidelines

## Feedback

* Star the [repo](https://gitlab.com/BlackPhrase/ogs-sdk) to show your support and interest
* Ask a question, request a new feature and report a bug [here](https://gitlab.com/BlackPhrase/ogs-sdk/-/issues)

## License

* [GNU GPLv3](LICENSE) for most of the codebase
* MIT for "interface" code inside of ogs-tier1 library ("Valve's interface/module factory" reimplementation; located in "goldsrc/tier1" and "goldsrc/public/tier1" folders)