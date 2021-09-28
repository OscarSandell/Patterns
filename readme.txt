/**********************************************************************
 *  M�nsterigenk�nning readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt):

/**********************************************************************
 * Empirisk analys
 *
 * Fyll i tabellen nedan med riktiga k�rtider i sekunder n�r det k�nns
 * vettigt att v�nta p� hela ber�kningen.
 * Ge uppskattningar av k�rtiden (baserat p� tidskomplexiteten)
 * i �vriga fall.
 *
 **********************************************************************/
    
      N       brute       sortering
 ----------------------------------
    150       2 ms        2 ms
    200       4 ms       22 ms
    300      21 ms       27 ms
    400      42 ms       41 ms
    800     282 ms       80 ms  
   1600    2280 ms      286 ms
   3200   18142 ms     1147 ms
   6400  145464 ms     4812 ms
  12800 1167181 ms    23188 ms


/**********************************************************************
 * Teoretisk analys
 *
 * Ge ordo-uttryck f�r v�rstafallstiden f�r programmen som en funktion
 * av N. Ge en kort motivering.
 *
 * Matchar brute-l�sningen sitt v�rstafall i praktiken, eller har den
 * ett medelfall som �r b�ttre?
 *
 **********************************************************************/

Brute: O(n^4) eller mer exakt O((n^4)/2)

Sortering:


/**********************************************************************
 * Energianv�ndning
 *
 * Antag att du anv�nder m�nsterigenk�nningsprogrammet f�r att analysera
 * data fr�n en kamera. Kameran sitter i en byggnad och tar en bild
 * p� stommen av byggnaden var 30:e minut. Bilden f�rbehandlas sedan
 * lite, innan punkter som representerar stommen skickas till
 * m�nsterigenk�nningsprogrammet. Hittas inte tillr�ckligt m�nga raka
 * linjer s� betyder det att n�got h�ller p� att g� s�nder, och
 * att byggnaden beh�ver noggrannare inspektion.
 *
 * Hur mycket energi sparar du p� ett �r om du anv�nder din snabbare
 * sorteringsl�sning i st�llet f�r brute-l�sningen? Du kan anta f�ljande:
 * - Systemet k�rs 24/7 under hela �ret.
 * - Inget annat k�rs p� det h�r systemet.
 * - Systemet drar 8 W n�r det inte g�r n�got (idle)
 * - Systemet drar 36 W n�r det arbetar (med 1 k�rna)
 * - R�kna med att ditt program k�rs var 30:e minut (= 2 g�nger/timme)
 * - F�r- och efterbehandling �r snabba, s� vi kan bortse fr�n dem
 * - Indata till programmet inneh�ller ca 6400 punkter
 * - Det �r inte skott�r (= 365 dagar)
 *
 * Att j�mf�ra med drar en kombinerad kyl/frys ca 200 kWh per �r
 * (enligt Energimyndigheten).
 *
 * Kom ih�g: energi m�ts ofta i kWh, vilket �r:
 *  energi (kWh) = effekt (kW) * tid (h)
 *
 * Tips: ett s�tt att r�kna p� �r att f�rst r�kna f�rbrukningen av
 * ett system som inte g�r n�got p� ett helt �r, sedan l�gga till
 * den extra f�rbrukningen (36 W - 8 W = 28 W) f�r tiden som systemet
 * �r aktiv.
 *
 * (Siffrorna �r l�st baserade p� en Intel i9-9900K, vi r�knar bara p�
 * CPU:n f�r enkelhets skull, besparingarna blir sannolikt st�rre om
 * vi r�knar p� st�rre delar av systemet, �ven om andra komponenter
 * ocks� drar str�m i "idle".)
 *
 **********************************************************************/

F�rbrukning av brute p� ett �r: 89,9 kWh tror vi om vi kan räkna

F�rbrukning av sotering p� ett �r: ? kWh

Skillnad: ? kWh

