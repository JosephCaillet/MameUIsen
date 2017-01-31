# MameUIsen
A gui for Mame

#Screenshots

![Games selection 1](https://raw.githubusercontent.com/JosephCaillet/MameUIsen/master/mameUIsen1.jpg)
![Games selection 2](https://raw.githubusercontent.com/JosephCaillet/MameUIsen/master/mameUIsen2.jpg)

#Compilation

Use cmake.

#Add games

Put your roms and screenshots into the `roms` and `screenshots` directory, and ask MameUIsen to rebuild games configuration. See the following section to do so.

#Usage

MameUIsen [ [-h | --help] | [ [-cf | --config-file] config_file_path] [ [-b | --build-category-rom-config-files] [bindingCatRomFile] ] ]

MameUIsen [-h | --help] : view help.
MameUIsen : start MameUIsen.
MameUIsen [-cf | --config-file] config_file_path] : launch MameUISen using an other config file, specified by the `config_file_path` argument.
MameUIsen [-b | --build-category-rom-config-files] [bindingCatRomFile] : rebuild MameUIsen games config file, using `bindingCatRomFile` file.
	If this argument is not specified, MameUIsen will not sort games by categories. A default file is provided here : `config/Genre.ini`.


#Configuration

See `config/general.cfg` for general configuration, for theme and UI see `themes/default/default.theme`.

## Fonts
* fipps by STEFANIE KOERNER (PHEIST)
* 04B_30__ by Yuji Oshimoto
* Arcade Future by Martin Sørensen
* ARCADE_N by Yuji Adachi
* ARCADE_R by Yuji Adachi
* ARCADEPI by Reekee of Dimenzioned
