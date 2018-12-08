# roomba
Fa uns mesos que tenim una persona que vé a casa i ens ajuda amb les feines... n'estem molt contents però darrerament sospitem que s'hi està molt menys temps del que hem pactat. Vé quan som fora i no tenim forma de saber quan de temps s'hi està... Sempre havia volgut fer alguna cosa amb arduino: ara n'he tingut l'excusa.

Aquest projecte és una xorrada: Si busques grans desenvolupaments o descobriments t'has equivocat de repositori (i d'usuari)! 
Això és un simple divertimento.

Com que tampoc volía complicar-me la vida (i arriscar-me a fer alguna cosa que no funcionés), vaig decidir muntar el projecte envers a una resistencia LDR: Un tipus de resistència que varia en funció de la llum que hi ha a l'entorn. La idea és situar això a prop de l'entrada, cada vegada que s'obri la porta del carrer la llum variarà de forma notòria, ho detectarem i ens ho guardarem en un registre de text.

Per controlar això hem fet servir una arduino petita xina que hem [trobat](https://www.amazon.es/dp/B01M7ZB2B4?aaxitk=gaqGsul2mgWlRdqk36D8Dw&pd_rd_i=B01M7ZB2B4&pf_rd_p=b4a87efe-46df-474d-b505-3bf1bb51624b&hsa_cr_id=9182184180602&sb-ci-n=productDescription&sb-ci-v=Elegoo%20UNO%20R3%20Tarjeta%20UNO%20R3%20Placa%20con%20Microcontrolador%20Basada%20en%20el%20ATmega328P%20ATMEGA16U2%20con%20Cable%20USB%20Compatible%20con%20Arduino%20UNO%20Tarjeta) a l'amazon!

Després d'estar-ho mirant m'adono que l'arduino no té RTC (real time clock) i que de poc ens servrà si no podem saber l'hora, per aquest motiu, vaig comprar també un mòdul RTC que em permeti saber l'hora actual: vaig comprar [aquest](https://www.amazon.es/WINGONEER-DS3231-AT24C32-precisi%C3%B3n-Arduino/dp/B01H5NAFUY/ref=sr_1_5?ie=UTF8&qid=1544285193&sr=8-5&keywords=Arduino+Rtc), com que no en sóc cap expert... simplement et diré que dona la hora i la data correctament: Potser la llibreria per tractar-ho es menja molta memòria, rellegint-la per sobre hi ha molt de codi que es podria eliminar i en aquest projecte tot continuaria funcionant.

Ara que ja sabem mesurar la llum i sabem l'hora que és... falta un lloc on desar-ho- com que ho volia tenir ràpid, en comptes d'enviar coses per wifi i haver de tenir algun servei escoltant en alguna banda vaig decidir gravar-ho en una SD local (en plan datalogger). Per aquest motiu vaig afegir-hi un microSD Adapter per aduino... [aquest](https://www.ebay.es/i/272536699694?chn=ps)

Ara sí, ja ho tenim tot, dissenyem el circuit amb l'eagle:

![esquema](https://github.com/indiketa/roomba/blob/master/assets/esquema.png "Esquema")

Primer vaig provar-ho tot en una protoboard i va funcionar, però el manyoc de cables per no fer res era considerable. Total que vaig decidir fer-me la placa amb l'EAGLE i fer-la imprimir per internet.La vaig imprimir a https://www.seeedstudio.io:

![placa cutre](https://github.com/indiketa/roomba/blob/master/assets/pcb.png =250x"Placa")
![placa cutre](https://github.com/indiketa/roomba/blob/master/assets/pcb2.jpg  =250x "Placa impresa")

No és el millor disseny ho sé, el proper invent el farem millor. 

I bàsicament així es com va quedar tot muntat:

![placa cutre](https://github.com/indiketa/roomba/blob/master/assets/muntada.jpg  =250x "Muntada1")
![placa cutre](https://github.com/indiketa/roomba/blob/master/assets/muntada2.jpg  =250x "Muntada2")

I acoplat a la arduino uno:

![placa cutre](https://github.com/indiketa/roomba/blob/master/assets/ambunor3.jpg  =250x "Acoblada")

Com veieu, al fi i al cap, controlar les hores era el menys important ;)
El cost final del projecte van ser 10€ per l'arduino, 3€ per l'RTC, 3€ per la controladora SD, 5€ per la placa (mínim 5 copies, me'n sobren 4 si algú les vol), i la resistencia LDR no ho sé: cèntims d'euro.

I vet aquí un gat i vet aquí un gos, que aquest compte ja s'ha fos.
