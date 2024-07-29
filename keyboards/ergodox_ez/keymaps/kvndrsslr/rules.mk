# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
# The following three lines are for firmware size optimization
# - not a problem I expect to run into on the moonlander
# LTO_ENABLE = yes
# CONSOLE_ENABLE = no
# COMMAND_ENABLE = no
# enable unicode maps for umlauts
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = yes
# enabled swap hands code
SWAP_HANDS_ENABLE = yes
COMBO_ENABLE = yes
