# Objektinis

Programa:
    Programa skirta skaičiuoti mokinių pažymių vidurkius ir gauti rezultatus pasirinktu formatu.
    Programoje yra galimybė įvesti mokinį ir jo rezultatus sugeneruoti mokinio balus, taip pat skaityti mokinių sąrašą iš failo.

Tikslas:
    0.3 versija skirta palyginti C++ kalbos duomenų struktūrų list ir vector spartą apdorojant didelius kiekius duomenų.

Sistemos specifikacijos:
    Procesorius: AMD Ryzen 7 7435HS, 3100 Mhz, 8 branduoliai, 16 loginių procesorių
    RAM: 16GB
    Diskas: SSD

Testavimas:

    Pateikti laikai vidutiniai per kelis testavimus

    Studentų skaičius: 1000

        Vector<Studentai>:
        Failų nuskaitymas: 0.00429844s
        Rikiavimas pagal pažymius: 0.00115516s
        Rikiavimas pagal vardą: 0.000773873s
        Studentų rūšiavimas: 0.000539068s
        Duomenų įrašymas į failus: 0.00276976s
        Pilnas veikimo laikas: 0.00953630s

        List<Studentai>:
        Failų nuskaitymas: 0.00441098s
        Rikiavimas pagal pažymius: 0.000396083s
        Rikiavimas pagal vardą: 0.000334981s
        Studentų rūšiavimas: 0.000519063s
        Duomenų įrašymas į failus: 0.00283785s
        Pilnas veikimo laikas: 0.00849896s

    Su 1000 studentų List turi spartesnį rikiavimą, kitose kategorijose skirtumai nežymūs.

    Studentų skaičius: 10000

        Vector<Studentai>:
        Failų nuskaitymas: 0.0801375s
        Rikiavimas pagal pažymius: 0.0162182s
        Rikiavimas pagal vardą: 0.00984555s
        Studentų rūšiavimas: 0.00624465s
        Duomenų įrašymas į failus: 0.0224558s
        Pilnas veikimo laikas: 0.1349017s

        List<Studentai>:
        Failų nuskaitymas: 0.074241s
        Rikiavimas pagal pažymius: 0.00616155s
        Rikiavimas pagal vardą: 0.00399334s
        Studentų rūšiavimas: 0.00442617s
        Duomenų įrašymas į failus: 0.0252468s
        Pilnas veikimo laikas: 0.1140689s

    List duomenų struktūra pasižymi greitesniu rikiavimu pagal pažymius ir vardą

    Studentų skaičius: 100000

        Vector<Studentai>:
        Failų nuskaitymas: 1.09426s
        Rikiavimas pagal pažymius: 0.197106s
        Rikiavimas pagal vardą: 0.105873s
        Studentų rūšiavimas: 0.0586521s
        Duomenų įrašymas į failus: 0.203254s
        Pilnas veikimo laikas: 1.6591451s

        List<Studentai>:
        Failų nuskaitymas:  0.973157s
        Rikiavimas pagal pažymius: 0.113715s
        Rikiavimas pagal vardą: 0.0549911s
        Studentų rūšiavimas: 0.0483787s
        Duomenų įrašymas į failus: 0.18008s
        Pilnas veikimo laikas: 1.3703218s

    Rikiavimas list greitesnis, kiti parametrai panašūs

    Studentų skaičius: 1000000 (milijonas)

        Vector<Studentai>:
        Failų nuskaitymas: 5.00494s
        Rikiavimas pagal pažymius: 2.82426s
        Rikiavimas pagal vardą: 1.27244s
        Studentų rūšiavimas: 0.749614s
        Duomenų įrašymas į failus: 2.12965s
        Pilnas veikimo laikas: 11.980904s

        List<Studentai>:
        Failų nuskaitymas: 4.85795s
        Rikiavimas pagal pažymius: 1.4554s
        Rikiavimas pagal vardą: 0.571668s
        Studentų rūšiavimas: 0.646082s
        Duomenų įrašymas į failus: 2.12742s
        Pilnas veikimo laikas: 9.65852s

    Rikiavimas list greitesnis, kiti parametrai panašūs, list nežymiai greitesnis

    Studentų skaičius: 10000000 (10 milijonų)

        Vector<Studentai>:
        Failų nuskaitymas: 50.1437s
        Rikiavimas pagal pažymius: 33.7627s
        Rikiavimas pagal vardą: 14.7195s
        Studentų rūšiavimas: 10.79s
        Duomenų įrašymas į failus: 21.3615s
        Pilnas veikimo laikas: 130.7774s

        List<Studentai>:
        Failų nuskaitymas: 46.8239s
        Rikiavimas pagal pažymius: 19.3993s
        Rikiavimas pagal vardą: 6.56693s
        Studentų rūšiavimas: 6.76617s
        Duomenų įrašymas į failus: 18.0148s
        Pilnas veikimo laikas: 97.5711s


Rezultatai:
Iš testavimo galima matyti, kad list struktūra atlieka operacijas kaip rikiavimas ir rūšiavimas sparčiau negu vector struktūra. Kiti parametrai, kaip failų nuskaitymas ir išvedimas į failus, nežymiai spartesni su list struktūra, skirtumas išryškėja didėjant duomenų kiekiui