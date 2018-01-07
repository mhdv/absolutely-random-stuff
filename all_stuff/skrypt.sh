# Michał Filipowicz
# nr 226393
# 05.01.2016
# Skrypt Lab4

# alias lhs='for i in G M K; do du -sh */ | grep [0-9]$i$'\t' |sort -nr; done'

for i in *.JPEG *.PNG;
do cp "$i" "oryginal_$i" |
	convert "$i" -resize "$1x$2" "$i"|
        xargs mv "$i" `echo "$i"|tr " " "_" |tr [:upper:] [:lower:]`|
	xargs tar -cvf zdjecia.tar *.jpeg *.png;
done


# Testy oraz komentarz:
# Skrypt generalnie działa poprawnie, zamienia wszystkie pliki .JPEG oraz
# .PNG na .jpeg-.png i zmienia ich wielkość na podaną w formacie "./skrypt.sh XxY".
# Zdjęcia są poprawnie przekonwertowane, a oryginalne nieprzerobione zdjęcia
# zapisują się pod nazwą "oryginal_".
# Problem pojawił się przy tworzeniu archiwum. Skrypt nie chciał reagować na
# użycie "$i", powodowało to nieodnalezienie plików. Użycie tej samej opcji
# bez argumentu "xargs" powodowało poprawne spakowanie archiwum, jednak z plikami
# nieprzerobionymi .JPEG oraz .PNG, co nie było celem zadania.
# Zastąpiłem "$i" wszystkimi plikami .jpeg oraz .png.
