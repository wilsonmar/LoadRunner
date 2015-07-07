This page describes my efforts to create an easy way for LoadRunner to be installed on Windows machines
by building a Chocolatey package.

If you don't already know, chocolatey.com hosts packages that can be downloaded and installed without additional user interaction. Look at the list of packages available already:

https://chocolatey.org/packages

## <a name="InstallChoco"> Install Chocolatey</a>
It uses Windows PowerShell. So to enable Chcolatey:

1) Open an internet browser and go to <a target="_blank" href="http://chocolatey.com">http://chocolatey.com</a>.

2) Highlight the string:

3) Press Ctrl+C to copy it to your Windows Clipboard.

4) Open a Windows Run command window.

5) Click on the black area and press Ctrl_V to paste the command. Press Enter.


## <a name="InstallLR"> Install LoadRunner Windows Load Generator</a>
To install the latest version of lr.lg (LoadRunner's Load Generator module):

```
cinst lr.lg -y
```

To install a specific version:

```
cinst lr.lg.12.2 -y
```

A typical expected response is:

???

Happy load testing!


## <a name="InstallLR"> Install LoadRunner Windows Load Generator</a>
To enable you to do the above, I first watched this movie which walks through the entire process of setting up a chocolatey nuget package, testing it, and pushing it out to the server:

https://www.youtube.com/watch?v=Wt_unjS_SUo

The movie was Uploaded by FerventCoder on Apr 26, 2011.
Packages maintained by Rob are at:
https://github.com/ferventcoder/chocolatey-packages


warmup is used by these instructions:
https://github.com/chocolatey/chocolateytemplates#welcome-to-the-simple-way-of-creating-chocolatey-packages

http://www.nuget.org/packages/chocolatey
mentions
https://github.com/chocolatey/choco/wiki/CreatePackages

https://github.com/chocolatey/choco/wiki/HelpersReference
