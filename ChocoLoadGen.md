This page describes my efforts to create an easy way for LoadRunner to be installed on Windows machines
by building a Chocolatey package.

If you don't already know, chocolatey.com hosts packages that can be downloaded and installed without additional user interaction.

## <a name="InstallChoco"> Install Chocolatey</a>
It uses Windows PowerShell. So to enable Chcolatey:

1) Open an internet browser and go to <a target="_blank" href="http://chocolatey.com">http://chocolatey.com</a>.

2) Highlight the string:

3) Press Ctrl+C to copy it to your Windows Clipboard.

4) Open a Windows Run command window.

5) Click on the black area and press Ctrl_V to paste the command. Press Enter.


## <a name="InstallLR"> Install LoadRunner Windows Load Generator</a>
To install the latest version:

```
cinst LR-LoadGen -y
```

To install a specific version:

```
cinst LR-LoadGen-12.2 -y
```
