## Ubuntu 22 problemas :/



#### Ativar gestos com três dedos no touchpad:

No arquivo **/etc/gdm3/custom.conf** comentar a linha:

`Wayland=false`

Depois rodar no terminal:

`sudo systemctl restart gdm3`

**Ativar o wayland atrapalha o compartilhamento de tela.*



#### Resetar o Alsa (linux sound archtecture)

`pulseaudio -k && sudo alsa force-reload`



#### Github key 

`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`
