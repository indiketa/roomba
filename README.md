# roomba
Fa uns mesos que tenim una persona que vé a casa i ens ajuda amb les feines... n'estem molt contents, però darrerament sospitem que s'hi està molt menys temps del que hem pactat. Aquesta persona vé quan som fora i no tenim forma de saber-ho... Sempre havía volgut fer alguna cosa amb arduino: ara en tenia l'oportunitat.

Aquest projecte és una xorrada, si hi busques grans desenvolupaments o descobriments, t'has equivocat de repositori! Aquest és un simple divertimento.

Com que tampoc volía complicar-me la vida (i arriscar-me a fer alguna cosa que no funcionés), vaig decidir muntar el projecte envers a una resistencia LDR: Un tipus de resistència que varia en funció de la llum que hi ha a l'entorn. La idea és situar això a prop de l'entrada, cada vegada que s'obri la porta del carrer la llum variarà de forma substancial, ho detectarem i ens ho guardarem en un registre (log).

Per controlar això hem fet servir una arduino petita xina que hem [trobat](https://www.amazon.es/dp/B01M7ZB2B4?aaxitk=gaqGsul2mgWlRdqk36D8Dw&pd_rd_i=B01M7ZB2B4&pf_rd_p=b4a87efe-46df-474d-b505-3bf1bb51624b&hsa_cr_id=9182184180602&sb-ci-n=productDescription&sb-ci-v=Elegoo%20UNO%20R3%20Tarjeta%20UNO%20R3%20Placa%20con%20Microcontrolador%20Basada%20en%20el%20ATmega328P%20ATMEGA16U2%20con%20Cable%20USB%20Compatible%20con%20Arduino%20UNO%20Tarjeta) a l'amazon!

Després d'estar-ho mirant m'adono que l'arduino no té RTC (real time clock) i que de poc ens servrà si no podem saber l'hora, per aquest motiu, vaig comprar també un mòdul RTC que em permeti saber l'hora actual: vaig comprar [aquest](https://www.amazon.es/WINGONEER-DS3231-AT24C32-precisi%C3%B3n-Arduino/dp/B01H5NAFUY/ref=sr_1_5?ie=UTF8&qid=1544285193&sr=8-5&keywords=Arduino+Rtc), com que no en soc cap expert... simplement diré que dona la hora i la data correctament ;)

I per acabar-ho de rematar, ara que ja sabem la llum que hi ha a la sala i l'hora... ens falta un lloc on desar-ho, com que ho volia tenir ràpid, en comptes d'enviar coses via wifi i haver de tenir alguna cosa escoltant vaig decidir gravar-ho en una SD local, per aquest motiu vaig haver de comprar un microSD Adapter per aduino... [aquest](https://www.ebay.es/i/272536699694?chn=ps)

Ara ja ho tenim tot, vam dissenyar el circuit amb l'eagle:

![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")

Primer vaig provar-ho tot en una protoboard, però el fet de tenir un manyoc de cables que em recordava al rack de comunicacions d'alguna empresa no m'acabava d'agradar, vaig aprendre una mica més d'EAGLE i vaig dissenyar la placa, que vaig imprimir a https://www.seeedstudio.io/:

![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")


I bàsicament així es com va quedar tot muntat:
![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")

I acoplat a la arduino uno:
![alt text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Logo Title Text 1")

Com veieu, al fi i al cap, controlar les hores era el menys important ;)
