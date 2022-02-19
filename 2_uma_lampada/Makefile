.PHONY: make copia sobe # com a ajuda de Renato Botelho (Garga @rbgarga via telegram )

NOME = $(shell find . -name '*.ino' | rev | cut -f 2- -d '.' | rev )
SKETCH = $(NOME).ino

include $(HOME)/Documentos/Arduino/makeEspArduino/makeEspArduino.mk

copia: make all
	-cp -f /tmp/mkESP/$(NOME)_generic/$(NOME).bin ./

sobe: make all copia

	python3 /home/thiago/.arduino15/packages/esp8266/hardware/esp8266/3.0.2/tools/espota.py -i 10.0.0.101 -p 8266 --auth= -f ./$(NOME).bin
	echo "Pronto!! :)"
	rm /tmp/mkESP/$(NOME)_generic/$(NOME).*
	rm *.bin
