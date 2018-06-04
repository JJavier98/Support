BadConsequence badConsequence = new BadConsequence("Pierdes 5 niveles y 3 tesoros visibles",
    5,3,0);
    Prize prize = new Prize(4,2);
    monstruos.add(new Monster("El rey de rosa",13,badConsequence,prize));
    
    
    badConsequence = new BadConsequence ("Te atrapan para llevarte de fiesta y "
            + "te dejan caer en mitad del vuelo.Descarta 1 mano visible y 1 mano"
            + "oculta",0, new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),
            new ArrayList(Arrays.asList(TreasureKind.ONEHAND)));
    prize= new Prize (4,1);
    monstruos.add(new Monster("Angeles de la noche ibicenca",14,badConsequence,prize));
    
    
    badConsequence = new BadConsequence ("Pierdes tu armadura visible y otra oculta",0,
    new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList(Arrays.asList(TreasureKind.ARMOR)));
    prize = new Prize(2,1);
    monstruos.add(new Monster("Byakhees de bonanza",8,badConsequence,prize));
    
    
    badConsequence = new BadConsequence ("Embobados con el lindo primigenio te descartas"
            + "de tu casco visible",0,new ArrayList(Arrays.asList(TreasureKind.HELMET)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("Chibithulhu",2,badConsequence,prize));
    
    badConsequence = new BadConsequence ("El primordial bostezo contagioso. Pierdes el calzado visible",
            0,new ArrayList(Arrays.asList(TreasureKind.SHOES)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("El sopor de Dunwich",2,badConsequence,prize)); 
    
    
    badConsequence = new BadConsequence ("Pierdes todos tus tesoros visibles",
            0,50,0);
    prize = new Prize(3,1);
    monstruos.add(new Monster("El gorron en el umbral",10,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Pierdes la armadura visible",
            0,new ArrayList(Arrays.asList(TreasureKind.ARMOR)),
            new ArrayList());
    prize = new Prize(2,1);
    monstruos.add(new Monster("H.P Munchcraft",6,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Siente bichos bajo la ropa. Descarta la"
            + "armadura visible",
            0,new ArrayList(Arrays.asList(TreasureKind.ARMOR)),
            new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("Bichgooth",2,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Toses los pulmones y pierdes 2 niveles",
            2,0,0);
    prize = new Prize(1,1);
    monstruos.add(new Monster("La que redacta en las tinieblas",2,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Estos monstruos resultan bastantes superficiales"
            + "y te aburren mortalmente. Estas muerto",true);
    prize = new Prize(2,1);
    monstruos.add(new Monster("Los hondos",8,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Pierdes 2 niveles y 2 tesoros ocultos.",
            2,0,2);
    prize = new Prize(2,1);
    monstruos.add(new Monster("Semillas Cthulhu",4,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Te intentas escaquear. Pierdes una mano visible.",
            0,new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList());
    prize = new Prize(2,1);
    monstruos.add(new Monster("Dameargo",1,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Da mucho asquito. Pierdes 3 niveles.",
            3,0,0);
    prize = new Prize(1,1);
    monstruos.add(new Monster("Pollipólipo volante",3,badConsequence,prize));
    
    badConsequence = new BadConsequence ("No le hace gracia que pronuncien mal "
            + "su nombre. Estas muerto", true);
    prize = new Prize(3,1);
    monstruos.add(new Monster("Yskhtihyssg-Goth",12,badConsequence,prize));
    
    badConsequence = new BadConsequence ("La familia te atrapa. Estas muerto",true);
    prize = new Prize(4,1);
    monstruos.add(new Monster("Familia feliz",1,badConsequence,prize));
    
    badConsequence = new BadConsequence ("La quinta directiva primaria te obliga a "
            + "perder 2 niveles y un tesoro 2 manos visibles",
            2,new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS)),new ArrayList());
    prize = new Prize(2,1);
    monstruos.add(new Monster("Roboggoth",8,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Te asusta en la noche. Pierdes un casco visible",
            0,new ArrayList(Arrays.asList(TreasureKind.HELMET)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("El espía",5,badConsequence,prize));
    
    badConsequence = new BadConsequence ("Menudo susto te llevas. Pierdes 2 niveles"
            + " y 5 tesoros libres.",
            2,5,0);
    prize = new Prize(1,1);
    monstruos.add(new Monster("El lenguas",20,badConsequence,prize));
    
    
    badConsequence = new BadConsequence ("Te faltan manos para\n" +
"tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos",
            3,new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS,TreasureKind.ONEHAND,TreasureKind.ONEHAND)),new ArrayList());
    prize = new Prize(1,1);
    monstruos.add(new Monster("Bicéfalo",20,badConsequence,prize));
