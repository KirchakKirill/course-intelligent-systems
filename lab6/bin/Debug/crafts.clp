
(defrule clear-message
(declare (salience 90))
?clear-msg-flg <- (clearmessage)
?sendmessage <- (sendmessagehalt ?msg)
=>
(retract ?clear-msg-flg)
(retract ?sendmessage)
)
(deftemplate item
(slot name (default none))
)
                
(defrule Abyssal-Blade
(item (name Skull-Basher))
(item (name Vanguard))
=>
(assert (item (name Abyssal-Blade)))
(assert (sendmessagehalt "Abyssal-Blade:Skull-Basher+Vanguard=Abyssal-Blade"))
(halt)
)

(defrule Aeon-Disk
(item (name Vitality-Booster))
(item (name Energy-Booster))
=>
(assert (item (name Aeon-Disk)))
(assert (sendmessagehalt "Aeon-Disk:Vitality-Booster+Energy-Booster=Aeon-Disk"))
(halt)
)

(defrule Aether-Lens
(item (name Energy-Booster))
(item (name Void-Stone))
=>
(assert (item (name Aether-Lens)))
(assert (sendmessagehalt "Aether-Lens:Energy-Booster+Void-Stone=Aether-Lens"))
(halt)
)

(defrule Aghanim-s-Scepter
(item (name Point-Booster))
(item (name Ogre-Club))
(item (name Blade-of-Alacrity))
(item (name Staff-of-Wizardry))
=>
(assert (item (name Aghanim-s-Scepter)))
(assert (sendmessagehalt "Aghanim-s-Scepter:Point-Booster+Ogre-Club+Blade-of-Alacrity+Staff-of-Wizardry=Aghanim-s-Scepter"))
(halt)
)

(defrule Aghanim-s-Shard
(item (name Point-Booster))
=>
(assert (item (name Aghanim-s-Shard)))
(assert (sendmessagehalt "Aghanim-s-Shard:Point-Booster=Aghanim-s-Shard"))
(halt)
)

(defrule Arcane-Blink
(item (name Blink-Dagger))
(item (name Mystic-Staff))
=>
(assert (item (name Arcane-Blink)))
(assert (sendmessagehalt "Arcane-Blink:Blink-Dagger+Mystic-Staff=Arcane-Blink"))
(halt)
)

(defrule Arcane-Boots
(item (name Boots-of-Speed))
(item (name Energy-Booster))
=>
(assert (item (name Arcane-Boots)))
(assert (sendmessagehalt "Arcane-Boots:Boots-of-Speed+Energy-Booster=Arcane-Boots"))
(halt)
)

(defrule Armlet-of-Mordiggian
(item (name Helm-of-Iron-Will))
(item (name Gloves-of-Haste))
(item (name Blades-of-Attack))
=>
(assert (item (name Armlet-of-Mordiggian)))
(assert (sendmessagehalt "Armlet-of-Mordiggian:Helm-of-Iron-Will+Gloves-of-Haste+Blades-of-Attack=Armlet-of-Mordiggian"))
(halt)
)

(defrule Assault-Cuirass
(item (name Platemail))
(item (name Hyperstone))
(item (name Chainmail))
=>
(assert (item (name Assault-Cuirass)))
(assert (sendmessagehalt "Assault-Cuirass:Platemail+Hyperstone+Chainmail=Assault-Cuirass"))
(halt)
)

(defrule Battle-Fury
(item (name Claymore))
(item (name Broadsword))
(item (name Perseverance))
(item (name Quelling-Blade))
=>
(assert (item (name Battle-Fury)))
(assert (sendmessagehalt "Battle-Fury:Claymore+Broadsword+Perseverance+Quelling-Blade=Battle-Fury"))
(halt)
)

(defrule Black-King-Bar
(item (name Ogre-Club))
(item (name Mithril-Hammer))
=>
(assert (item (name Black-King-Bar)))
(assert (sendmessagehalt "Black-King-Bar:Ogre-Club+Mithril-Hammer=Black-King-Bar"))
(halt)
)

(defrule Blade-Mail
(item (name Broadsword))
(item (name Chainmail))
(item (name Robe-of-the-Magi))
=>
(assert (item (name Blade-Mail)))
(assert (sendmessagehalt "Blade-Mail:Broadsword+Chainmail+Robe-of-the-Magi=Blade-Mail"))
(halt)
)

(defrule Block-of-Cheese
(item (name Greater-Healing-Lotus))
(item (name Cheese))
=>
(assert (item (name Block-of-Cheese)))
(assert (sendmessagehalt "Block-of-Cheese:Greater-Healing-Lotus+Cheese=Block-of-Cheese"))
(halt)
)

(defrule Bloodthorn
(item (name Orchid-Malevolence))
(item (name Crystalys))
=>
(assert (item (name Bloodthorn)))
(assert (sendmessagehalt "Bloodthorn:Orchid-Malevolence+Crystalys=Bloodthorn"))
(halt)
)

(defrule Boots-of-Bearing
(item (name Tranquil-Boots))
(item (name Drum-of-Endurance))
=>
(assert (item (name Boots-of-Bearing)))
(assert (sendmessagehalt "Boots-of-Bearing:Tranquil-Boots+Drum-of-Endurance=Boots-of-Bearing"))
(halt)
)

(defrule Buckler
(item (name Ring-of-Protection))
=>
(assert (item (name Buckler)))
(assert (sendmessagehalt "Buckler:Ring-of-Protection=Buckler"))
(halt)
)

(defrule Crimson-Guard
(item (name Vanguard))
(item (name Buckler))
=>
(assert (item (name Crimson-Guard)))
(assert (sendmessagehalt "Crimson-Guard:Vanguard+Buckler=Crimson-Guard"))
(halt)
)

(defrule Crystalys
(item (name Broadsword))
(item (name Blades-of-Attack))
=>
(assert (item (name Crystalys)))
(assert (sendmessagehalt "Crystalys:Broadsword+Blades-of-Attack=Crystalys"))
(halt)
)

(defrule Dagon
(item (name Staff-of-Wizardry))
(item (name Null-Talisman))
=>
(assert (item (name Dagon)))
(assert (sendmessagehalt "Dagon:Staff-of-Wizardry+Null-Talisman=Dagon"))
(halt)
)

(defrule Daedalus
(item (name Crystalys))
(item (name Demon-Edge))
=>
(assert (item (name Daedalus)))
(assert (sendmessagehalt "Daedalus:Crystalys+Demon-Edge=Daedalus"))
(halt)
)

(defrule Desolator
(item (name Mithril-Hammer))
(item (name Mithril-Hammer))
=>
(assert (item (name Desolator)))
(assert (sendmessagehalt "Desolator:Mithril-Hammer+Mithril-Hammer=Desolator"))
(halt)
)

(defrule Diffusal-Blade
(item (name Blade-of-Alacrity))
(item (name Robe-of-the-Magi))
=>
(assert (item (name Diffusal-Blade)))
(assert (sendmessagehalt "Diffusal-Blade:Blade-of-Alacrity+Robe-of-the-Magi=Diffusal-Blade"))
(halt)
)

(defrule Disperser
(item (name Diffusal-Blade))
(item (name Demon-Edge))
=>
(assert (item (name Disperser)))
(assert (sendmessagehalt "Disperser:Diffusal-Blade+Demon-Edge=Disperser"))
(halt)
)

(defrule Divine-Rapier
(item (name Sacred-Relic))
(item (name Demon-Edge))
=>
(assert (item (name Divine-Rapier)))
(assert (sendmessagehalt "Divine-Rapier:Sacred-Relic+Demon-Edge=Divine-Rapier"))
(halt)
)

(defrule Dragon-Lance
(item (name Ogre-Club))
(item (name Band-of-Elvenskin))
=>
(assert (item (name Dragon-Lance)))
(assert (sendmessagehalt "Dragon-Lance:Ogre-Club+Band-of-Elvenskin=Dragon-Lance"))
(halt)
)

(defrule Drum-of-Endurance
(item (name Robe-of-the-Magi))
(item (name Belt-of-Strength))
(item (name Wind-Lace))
=>
(assert (item (name Drum-of-Endurance)))
(assert (sendmessagehalt "Drum-of-Endurance:Robe-of-the-Magi+Belt-of-Strength+Wind-Lace=Drum-of-Endurance"))
(halt)
)

(defrule Echo-Sabre
(item (name Oblivion-Staff))
(item (name Ogre-Club))
=>
(assert (item (name Echo-Sabre)))
(assert (sendmessagehalt "Echo-Sabre:Oblivion-Staff+Ogre-Club=Echo-Sabre"))
(halt)
)

(defrule Eternal-Shroud
(item (name Cloak))
(item (name Ogre-Axe))
(item (name Ring-of-Health))
=>
(assert (item (name Eternal-Shroud)))
(assert (sendmessagehalt "Eternal-Shroud:Cloak+Ogre-Axe+Ring-of-Health=Eternal-Shroud"))
(halt)
)

(defrule Ethereal-Blade
(item (name Kaya))
(item (name Ghost-Scepter))
=>
(assert (item (name Ethereal-Blade)))
(assert (sendmessagehalt "Ethereal-Blade:Kaya+Ghost-Scepter=Ethereal-Blade"))
(halt)
)

(defrule Eul-s-Scepter-of-Divinity
(item (name Staff-of-Wizardry))
(item (name Sage-s-Mask))
(item (name Wind-Lace))
=>
(assert (item (name Eul-s-Scepter-of-Divinity)))
(assert (sendmessagehalt "Eul-s-Scepter-of-Divinity:Staff-of-Wizardry+Sage-s-Mask+Wind-Lace=Eul-s-Scepter-of-Divinity"))
(halt)
)

(defrule Eye-of-Skadi
(item (name Ultimate-Orb))
(item (name Ultimate-Orb))
(item (name Point-Booster))
=>
(assert (item (name Eye-of-Skadi)))
(assert (sendmessagehalt "Eye-of-Skadi:Ultimate-Orb+Ultimate-Orb+Point-Booster=Eye-of-Skadi"))
(halt)
)

(defrule Falcon-Blade
(item (name Fluffy-Hat))
(item (name Sage-s-Mask))
(item (name Blades-of-Attack))
=>
(assert (item (name Falcon-Blade)))
(assert (sendmessagehalt "Falcon-Blade:Fluffy-Hat+Sage-s-Mask+Blades-of-Attack=Falcon-Blade"))
(halt)
)

(defrule Force-Staff
(item (name Staff-of-Wizardry))
(item (name Ring-of-Regen))
=>
(assert (item (name Force-Staff)))
(assert (sendmessagehalt "Force-Staff:Staff-of-Wizardry+Ring-of-Regen=Force-Staff"))
(halt)
)

(defrule Gleipnir
(item (name Maelstrom))
(item (name Rod-of-Atos))
=>
(assert (item (name Gleipnir)))
(assert (sendmessagehalt "Gleipnir:Maelstrom+Rod-of-Atos=Gleipnir"))
(halt)
)

(defrule Glimmer-Cape
(item (name Shadow-Amulet))
(item (name Cloak))
=>
(assert (item (name Glimmer-Cape)))
(assert (sendmessagehalt "Glimmer-Cape:Shadow-Amulet+Cloak=Glimmer-Cape"))
(halt)
)

(defrule Great-Healing-Lotus
(item (name Healing-Lotus))
=>
(assert (item (name Great-Healing-Lotus)))
(assert (sendmessagehalt "Great-Healing-Lotus:Healing-Lotus=Great-Healing-Lotus"))
(halt)
)

(defrule Greater-Healing-Lotus
(item (name Great-Healing-Lotus))
=>
(assert (item (name Greater-Healing-Lotus)))
(assert (sendmessagehalt "Greater-Healing-Lotus:Great-Healing-Lotus=Greater-Healing-Lotus"))
(halt)
)

(defrule Guardian-Greaves
(item (name Arcane-Boots))
(item (name Mekansm))
=>
(assert (item (name Guardian-Greaves)))
(assert (sendmessagehalt "Guardian-Greaves:Arcane-Boots+Mekansm=Guardian-Greaves"))
(halt)
)

(defrule Hand-of-Midas
(item (name Gloves-of-Haste))
=>
(assert (item (name Hand-of-Midas)))
(assert (sendmessagehalt "Hand-of-Midas:Gloves-of-Haste=Hand-of-Midas"))
(halt)
)

(defrule Heart-of-Tarrasque
(item (name Reaver))
(item (name Vitality-Booster))
=>
(assert (item (name Heart-of-Tarrasque)))
(assert (sendmessagehalt "Heart-of-Tarrasque:Reaver+Vitality-Booster=Heart-of-Tarrasque"))
(halt)
)

(defrule Helm-of-the-Dominator
(item (name Helm-of-Iron-Will))
(item (name Morbid-Mask))
=>
(assert (item (name Helm-of-the-Dominator)))
(assert (sendmessagehalt "Helm-of-the-Dominator:Helm-of-Iron-Will+Morbid-Mask=Helm-of-the-Dominator"))
(halt)
)

(defrule Hood-of-Defiance
(item (name Ring-of-Health))
(item (name Cloak))
=>
(assert (item (name Hood-of-Defiance)))
(assert (sendmessagehalt "Hood-of-Defiance:Ring-of-Health+Cloak=Hood-of-Defiance"))
(halt)
)

(defrule Hurricane-Pike
(item (name Force-Staff))
(item (name Dragon-Lance))
=>
(assert (item (name Hurricane-Pike)))
(assert (sendmessagehalt "Hurricane-Pike:Force-Staff+Dragon-Lance=Hurricane-Pike"))
(halt)
)

(defrule Holy-Locket
(item (name Diadem))
(item (name Headdress))
(item (name Magic-Wand))
=>
(assert (item (name Holy-Locket)))
(assert (sendmessagehalt "Holy-Locket:Diadem+Headdress+Magic-Wand=Holy-Locket"))
(halt)
)

(defrule Harpoon
(item (name Echo-Sabre))
(item (name Diadem))
=>
(assert (item (name Harpoon)))
(assert (sendmessagehalt "Harpoon:Echo-Sabre+Diadem=Harpoon"))
(halt)
)

(defrule Headdress
(item (name Ring-of-Regen))
=>
(assert (item (name Headdress)))
(assert (sendmessagehalt "Headdress:Ring-of-Regen=Headdress"))
(halt)
)

(defrule Heaven-s-Halberd
(item (name Sange))
(item (name Talisman-of-Evasion))
=>
(assert (item (name Heaven-s-Halberd)))
(assert (sendmessagehalt "Heaven-s-Halberd:Sange+Talisman-of-Evasion=Heaven-s-Halberd"))
(halt)
)

(defrule Helm-of-the-Overlord
(item (name Helm-of-the-Dominator))
(item (name Vladmir-s-Offering))
=>
(assert (item (name Helm-of-the-Overlord)))
(assert (sendmessagehalt "Helm-of-the-Overlord:Helm-of-the-Dominator+Vladmir-s-Offering=Helm-of-the-Overlord"))
(halt)
)

(defrule Kaya
(item (name Staff-of-Wizardry))
(item (name Robe-of-the-Magi))
=>
(assert (item (name Kaya)))
(assert (sendmessagehalt "Kaya:Staff-of-Wizardry+Robe-of-the-Magi=Kaya"))
(halt)
)

(defrule Kaya-and-Sange
(item (name Sange))
(item (name Kaya))
=>
(assert (item (name Kaya-and-Sange)))
(assert (sendmessagehalt "Kaya-and-Sange:Sange+Kaya=Kaya-and-Sange"))
(halt)
)

(defrule Linken-s-Sphere
(item (name Perseverance))
(item (name Ultimate-Orb))
=>
(assert (item (name Linken-s-Sphere)))
(assert (sendmessagehalt "Linken-s-Sphere:Perseverance+Ultimate-Orb=Linken-s-Sphere"))
(halt)
)

(defrule Lotus-Orb
(item (name Perserverance))
(item (name Plate-Mail))
=>
(assert (item (name Lotus-Orb)))
(assert (sendmessagehalt "Lotus-Orb:Perserverance+Plate-Mail=Lotus-Orb"))
(halt)
)

(defrule Maelstrom
(item (name Gloves-of-Haste))
(item (name Mithril-Hammer))
=>
(assert (item (name Maelstrom)))
(assert (sendmessagehalt "Maelstrom:Gloves-of-Haste+Mithril-Hammer=Maelstrom"))
(halt)
)

(defrule Mjollnir
(item (name Maelstrom))
(item (name Hyperstone))
=>
(assert (item (name Mjollnir)))
(assert (sendmessagehalt "Mjollnir:Maelstrom+Hyperstone=Mjollnir"))
(halt)
)

(defrule Monkey-King-Bar
(item (name Demon-Edge))
(item (name Javelin))
(item (name Quarterstaff))
=>
(assert (item (name Monkey-King-Bar)))
(assert (sendmessagehalt "Monkey-King-Bar:Demon-Edge+Javelin+Quarterstaff=Monkey-King-Bar"))
(halt)
)

(defrule Mage-Slayer
(item (name Cloak))
(item (name Oblivion-Staff))
=>
(assert (item (name Mage-Slayer)))
(assert (sendmessagehalt "Mage-Slayer:Cloak+Oblivion-Staff=Mage-Slayer"))
(halt)
)

(defrule Magic-Wand
(item (name Magic-Stick))
(item (name Iron-Branch))
=>
(assert (item (name Magic-Wand)))
(assert (sendmessagehalt "Magic-Wand:Magic-Stick+Iron-Branch=Magic-Wand"))
(halt)
)

(defrule Manta-Style
(item (name Yasha))
(item (name Ultimate-Orb))
=>
(assert (item (name Manta-Style)))
(assert (sendmessagehalt "Manta-Style:Yasha+Ultimate-Orb=Manta-Style"))
(halt)
)

(defrule Mask-of-Madness
(item (name Morbid-Mask))
(item (name Quarterstaff))
=>
(assert (item (name Mask-of-Madness)))
(assert (sendmessagehalt "Mask-of-Madness:Morbid-Mask+Quarterstaff=Mask-of-Madness"))
(halt)
)

(defrule Medallion-of-Courage
(item (name Chainmail))
(item (name Sage-s-Mask))
(item (name Blight-Stone))
=>
(assert (item (name Medallion-of-Courage)))
(assert (sendmessagehalt "Medallion-of-Courage:Chainmail+Sage-s-Mask+Blight-Stone=Medallion-of-Courage"))
(halt)
)

(defrule Mekansm
(item (name Meteor-Hammer))
(item (name Mind-Breaker))
=>
(assert (item (name Mekansm)))
(assert (sendmessagehalt "Mekansm:Meteor-Hammer+Mind-Breaker=Mekansm"))
(halt)
)

(defrule Moon-Shard
(item (name Hyperstone))
=>
(assert (item (name Moon-Shard)))
(assert (sendmessagehalt "Moon-Shard:Hyperstone=Moon-Shard"))
(halt)
)

(defrule Necronomicon
(item (name Sage-s-Mask))
(item (name Belt-of-Strength))
=>
(assert (item (name Necronomicon)))
(assert (sendmessagehalt "Necronomicon:Sage-s-Mask+Belt-of-Strength=Necronomicon"))
(halt)
)

(defrule Nullifier
(item (name Sacred-Relic))
(item (name Helm-of-Iron-Will))
=>
(assert (item (name Nullifier)))
(assert (sendmessagehalt "Nullifier:Sacred-Relic+Helm-of-Iron-Will=Nullifier"))
(halt)
)

(defrule Orchid-Malevolence
(item (name Oblivion-Staff))
(item (name Oblivion-Staff))
=>
(assert (item (name Orchid-Malevolence)))
(assert (sendmessagehalt "Orchid-Malevolence:Oblivion-Staff+Oblivion-Staff=Orchid-Malevolence"))
(halt)
)

(defrule Octarine-Core
(item (name Void-Stone))
(item (name Soul-Booster))
=>
(assert (item (name Octarine-Core)))
(assert (sendmessagehalt "Octarine-Core:Void-Stone+Soul-Booster=Octarine-Core"))
(halt)
)

(defrule Orb-of-Corrosion
(item (name Orb-of-Venom))
(item (name Blight-Stone))
(item (name Fluffy-Hat))
=>
(assert (item (name Orb-of-Corrosion)))
(assert (sendmessagehalt "Orb-of-Corrosion:Orb-of-Venom+Blight-Stone+Fluffy-Hat=Orb-of-Corrosion"))
(halt)
)

(defrule Overwhelming-Blink
(item (name Blink-Dagger))
(item (name Reaver))
=>
(assert (item (name Overwhelming-Blink)))
(assert (sendmessagehalt "Overwhelming-Blink:Blink-Dagger+Reaver=Overwhelming-Blink"))
(halt)
)

(defrule Pavise
(item (name Void-Stone))
(item (name Ring-of-Protection))
(item (name Fluffy-Hat))
=>
(assert (item (name Pavise)))
(assert (sendmessagehalt "Pavise:Void-Stone+Ring-of-Protection+Fluffy-Hat=Pavise"))
(halt)
)

(defrule Perseverance
(item (name Ring-of-Health))
(item (name Void-Stone))
=>
(assert (item (name Perseverance)))
(assert (sendmessagehalt "Perseverance:Ring-of-Health+Void-Stone=Perseverance"))
(halt)
)

(defrule Phase-Boots
(item (name Boots-of-Speed))
(item (name Chainmail))
(item (name Blades-of-Attack))
=>
(assert (item (name Phase-Boots)))
(assert (sendmessagehalt "Phase-Boots:Boots-of-Speed+Chainmail+Blades-of-Attack=Phase-Boots"))
(halt)
)

(defrule Phylactery
(item (name Diadem))
(item (name Point-Booster))
=>
(assert (item (name Phylactery)))
(assert (sendmessagehalt "Phylactery:Diadem+Point-Booster=Phylactery"))
(halt)
)

(defrule Pipe-of-Insight
(item (name Cloak))
(item (name Headdress))
(item (name Ring-of-Health))
=>
(assert (item (name Pipe-of-Insight)))
(assert (sendmessagehalt "Pipe-of-Insight:Cloak+Headdress+Ring-of-Health=Pipe-of-Insight"))
(halt)
)

(defrule Power-Treads
(item (name Boots-of-Speed))
(item (name Belt-of-Strength))
=>
(assert (item (name Power-Treads)))
(assert (sendmessagehalt "Power-Treads:Boots-of-Speed+Belt-of-Strength=Power-Treads"))
(halt)
)

(defrule Power-Treads
(item (name Boots-of-Speed))
(item (name Band-of-Elvenskin))
=>
(assert (item (name Power-Treads)))
(assert (sendmessagehalt "Power-Treads:Boots-of-Speed+Band-of-Elvenskin=Power-Treads"))
(halt)
)

(defrule Power-Treads
(item (name Boots-of-Speed))
(item (name Robe-of-the-Magi))
=>
(assert (item (name Power-Treads)))
(assert (sendmessagehalt "Power-Treads:Boots-of-Speed+Robe-of-the-Magi=Power-Treads"))
(halt)
)

(defrule Radiance
(item (name Sacred-Relic))
(item (name Talisman-of-Evasion))
=>
(assert (item (name Radiance)))
(assert (sendmessagehalt "Radiance:Sacred-Relic+Talisman-of-Evasion=Radiance"))
(halt)
)

(defrule Refresher-Orb
(item (name Cornucopia))
=>
(assert (item (name Refresher-Orb)))
(assert (sendmessagehalt "Refresher-Orb:Cornucopia=Refresher-Orb"))
(halt)
)

(defrule Rod-of-Atos
(item (name Staff-of-Wizardry))
(item (name Vitality-Booster))
=>
(assert (item (name Rod-of-Atos)))
(assert (sendmessagehalt "Rod-of-Atos:Staff-of-Wizardry+Vitality-Booster=Rod-of-Atos"))
(halt)
)

(defrule Sange
(item (name Ogre-Club))
(item (name Belt-of-Strength))
=>
(assert (item (name Sange)))
(assert (sendmessagehalt "Sange:Ogre-Club+Belt-of-Strength=Sange"))
(halt)
)

(defrule Sange-and-Yasha
(item (name Sange))
(item (name Yasha))
=>
(assert (item (name Sange-and-Yasha)))
(assert (sendmessagehalt "Sange-and-Yasha:Sange+Yasha=Sange-and-Yasha"))
(halt)
)

(defrule Satanic
(item (name Morbid-Mask))
(item (name Reaver))
=>
(assert (item (name Satanic)))
(assert (sendmessagehalt "Satanic:Morbid-Mask+Reaver=Satanic"))
(halt)
)

(defrule Scythe-of-Vyse
(item (name Mystic-Staff))
(item (name Ultimate-Orb))
=>
(assert (item (name Scythe-of-Vyse)))
(assert (sendmessagehalt "Scythe-of-Vyse:Mystic-Staff+Ultimate-Orb=Scythe-of-Vyse"))
(halt)
)

(defrule Shiva-s-Guard
(item (name Platemail))
(item (name Mystic-Staff))
=>
(assert (item (name Shiva-s-Guard)))
(assert (sendmessagehalt "Shiva-s-Guard:Platemail+Mystic-Staff=Shiva-s-Guard"))
(halt)
)

(defrule Silver-Edge
(item (name Shadow-Blade))
(item (name Sange))
=>
(assert (item (name Silver-Edge)))
(assert (sendmessagehalt "Silver-Edge:Shadow-Blade+Sange=Silver-Edge"))
(halt)
)

(defrule Skull-Basher
(item (name Javelin))
(item (name Belt-of-Strength))
=>
(assert (item (name Skull-Basher)))
(assert (sendmessagehalt "Skull-Basher:Javelin+Belt-of-Strength=Skull-Basher"))
(halt)
)

(defrule Solar-Crest
(item (name Medallion-of-Courage))
(item (name Talisman-of-Evasion))
=>
(assert (item (name Solar-Crest)))
(assert (sendmessagehalt "Solar-Crest:Medallion-of-Courage+Talisman-of-Evasion=Solar-Crest"))
(halt)
)

(defrule Spirit-Vessel
(item (name Urn-of-Shadows))
(item (name Wind-Lace))
=>
(assert (item (name Spirit-Vessel)))
(assert (sendmessagehalt "Spirit-Vessel:Urn-of-Shadows+Wind-Lace=Spirit-Vessel"))
(halt)
)

(defrule Shadow-Blade
(item (name Shadow-Amulet))
(item (name Blitz-Knuckles))
(item (name Broadsword))
=>
(assert (item (name Shadow-Blade)))
(assert (sendmessagehalt "Shadow-Blade:Shadow-Amulet+Blitz-Knuckles+Broadsword=Shadow-Blade"))
(halt)
)

(defrule Solar-Crest
(item (name Medallion-of-Courage))
(item (name Crown))
(item (name Wind-Lace))
=>
(assert (item (name Solar-Crest)))
(assert (sendmessagehalt "Solar-Crest:Medallion-of-Courage+Crown+Wind-Lace=Solar-Crest"))
(halt)
)

(defrule Tranquil-Boots
(item (name Boots-of-Speed))
(item (name Wind-Lace))
(item (name Ring-of-Regen))
=>
(assert (item (name Tranquil-Boots)))
(assert (sendmessagehalt "Tranquil-Boots:Boots-of-Speed+Wind-Lace+Ring-of-Regen=Tranquil-Boots"))
(halt)
)

(defrule Urn-of-Shadows
(item (name Sage-s-Mask))
(item (name Circlet))
(item (name Ring-of-Protection))
=>
(assert (item (name Urn-of-Shadows)))
(assert (sendmessagehalt "Urn-of-Shadows:Sage-s-Mask+Circlet+Ring-of-Protection=Urn-of-Shadows"))
(halt)
)

(defrule Vladimir-s-Offering
(item (name Ring-of-Basilius))
(item (name Morbid-Mask))
=>
(assert (item (name Vladimir-s-Offering)))
(assert (sendmessagehalt "Vladimir-s-Offering:Ring-of-Basilius+Morbid-Mask=Vladimir-s-Offering"))
(halt)
)

(defrule Yasha
(item (name Blade-of-Alacrity))
(item (name Boots-of-Elvenskin))
=>
(assert (item (name Yasha)))
(assert (sendmessagehalt "Yasha:Blade-of-Alacrity+Boots-of-Elvenskin=Yasha"))
(halt)
)

(defrule Yasha-and-Kaya
(item (name Kaya))
(item (name Yasha))
=>
(assert (item (name Yasha-and-Kaya)))
(assert (sendmessagehalt "Yasha-and-Kaya:Kaya+Yasha=Yasha-and-Kaya"))
(halt)
)

(defrule Aetherforged-Blade
(item (name Crystalys))
(item (name Energy-Booster))
=>
(assert (item (name Aetherforged-Blade)))
(assert (sendmessagehalt "Aetherforged-Blade:Crystalys+Energy-Booster=Aetherforged-Blade"))
(halt)
)

(defrule Bloodshroud-Amulet
(item (name Vanguard))
(item (name Morbid-Mask))
=>
(assert (item (name Bloodshroud-Amulet)))
(assert (sendmessagehalt "Bloodshroud-Amulet:Vanguard+Morbid-Mask=Bloodshroud-Amulet"))
(halt)
)

(defrule Cursed-Essence
(item (name Ghost-Scepter))
(item (name Blade-of-Alacrity))
=>
(assert (item (name Cursed-Essence)))
(assert (sendmessagehalt "Cursed-Essence:Ghost-Scepter+Blade-of-Alacrity=Cursed-Essence"))
(halt)
)

(defrule Dire-s-Bane
(item (name Demon-Edge))
(item (name Demon-Edge))
=>
(assert (item (name Dire-s-Bane)))
(assert (sendmessagehalt "Dire-s-Bane:Demon-Edge+Demon-Edge=Dire-s-Bane"))
(halt)
)

(defrule Elemental-Quiver
(item (name Wind-Lace))
(item (name Javelin))
=>
(assert (item (name Elemental-Quiver)))
(assert (sendmessagehalt "Elemental-Quiver:Wind-Lace+Javelin=Elemental-Quiver"))
(halt)
)

(defrule Essence-of-the-Abyss
(item (name Ring-of-Health))
(item (name Perseverance))
=>
(assert (item (name Essence-of-the-Abyss)))
(assert (sendmessagehalt "Essence-of-the-Abyss:Ring-of-Health+Perseverance=Essence-of-the-Abyss"))
(halt)
)

(defrule Flameheart-Ring
(item (name Ring-of-Basilius))
(item (name Helm-of-Iron-Will))
=>
(assert (item (name Flameheart-Ring)))
(assert (sendmessagehalt "Flameheart-Ring:Ring-of-Basilius+Helm-of-Iron-Will=Flameheart-Ring"))
(halt)
)

(defrule Frostbound-Gauntlets
(item (name Gloves-of-Haste))
(item (name Orb-of-Venom))
=>
(assert (item (name Frostbound-Gauntlets)))
(assert (sendmessagehalt "Frostbound-Gauntlets:Gloves-of-Haste+Orb-of-Venom=Frostbound-Gauntlets"))
(halt)
)

(defrule Gem-of-Resilience
(item (name Hood-of-Defiance))
(item (name Vitality-Booster))
=>
(assert (item (name Gem-of-Resilience)))
(assert (sendmessagehalt "Gem-of-Resilience:Hood-of-Defiance+Vitality-Booster=Gem-of-Resilience"))
(halt)
)

(defrule Ghostly-Dagger
(item (name Blink-Dagger))
(item (name Ghost-Scepter))
=>
(assert (item (name Ghostly-Dagger)))
(assert (sendmessagehalt "Ghostly-Dagger:Blink-Dagger+Ghost-Scepter=Ghostly-Dagger"))
(halt)
)

(defrule Gravetide-Boots
(item (name Arcane-Boots))
(item (name Guardian-Greaves))
=>
(assert (item (name Gravetide-Boots)))
(assert (sendmessagehalt "Gravetide-Boots:Arcane-Boots+Guardian-Greaves=Gravetide-Boots"))
(halt)
)

(defrule Infernal-Cane
(item (name Force-Staff))
(item (name Staff-of-Wizardry))
=>
(assert (item (name Infernal-Cane)))
(assert (sendmessagehalt "Infernal-Cane:Force-Staff+Staff-of-Wizardry=Infernal-Cane"))
(halt)
)

(defrule Jungle-Striders
(item (name Tranquil-Boots))
(item (name Iron-Branch))
=>
(assert (item (name Jungle-Striders)))
(assert (sendmessagehalt "Jungle-Striders:Tranquil-Boots+Iron-Branch=Jungle-Striders"))
(halt)
)

(defrule Mystic-Talisman
(item (name Yasha))
(item (name Ultimate-Orb))
=>
(assert (item (name Mystic-Talisman)))
(assert (sendmessagehalt "Mystic-Talisman:Yasha+Ultimate-Orb=Mystic-Talisman"))
(halt)
)

(defrule Nether-Cloak
(item (name Shadow-Amulet))
(item (name Cloak))
=>
(assert (item (name Nether-Cloak)))
(assert (sendmessagehalt "Nether-Cloak:Shadow-Amulet+Cloak=Nether-Cloak"))
(halt)
)

(defrule Obsidian-Shield
(item (name Vanguard))
(item (name Mystic-Staff))
=>
(assert (item (name Obsidian-Shield)))
(assert (sendmessagehalt "Obsidian-Shield:Vanguard+Mystic-Staff=Obsidian-Shield"))
(halt)
)

(defrule Plaguebringer-Staff
(item (name Diffusal-Blade))
(item (name Oblivion-Staff))
=>
(assert (item (name Plaguebringer-Staff)))
(assert (sendmessagehalt "Plaguebringer-Staff:Diffusal-Blade+Oblivion-Staff=Plaguebringer-Staff"))
(halt)
)

(defrule Radiant-Crest
(item (name Medallion-of-Courage))
(item (name Solar-Crest))
=>
(assert (item (name Radiant-Crest)))
(assert (sendmessagehalt "Radiant-Crest:Medallion-of-Courage+Solar-Crest=Radiant-Crest"))
(halt)
)

(defrule Sacred-Vessel
(item (name Urn-of-Shadows))
(item (name Spirit-Vessel))
=>
(assert (item (name Sacred-Vessel)))
(assert (sendmessagehalt "Sacred-Vessel:Urn-of-Shadows+Spirit-Vessel=Sacred-Vessel"))
(halt)
)

(defrule Soulbound-Scythe
(item (name Scythe-of-Vyse))
(item (name Eul-s-Scepter-of-Divinity))
=>
(assert (item (name Soulbound-Scythe)))
(assert (sendmessagehalt "Soulbound-Scythe:Scythe-of-Vyse+Eul-s-Scepter-of-Divinity=Soulbound-Scythe"))
(halt)
)

(defrule Starshard-Bow
(item (name Maelstrom))
(item (name Yasha))
=>
(assert (item (name Starshard-Bow)))
(assert (sendmessagehalt "Starshard-Bow:Maelstrom+Yasha=Starshard-Bow"))
(halt)
)

(defrule Thunderstrike-Warhammer
(item (name Sange))
(item (name Mjollnir))
=>
(assert (item (name Thunderstrike-Warhammer)))
(assert (sendmessagehalt "Thunderstrike-Warhammer:Sange+Mjollnir=Thunderstrike-Warhammer"))
(halt)
)

(defrule Vanguard
(item (name Vitality-Booster))
(item (name Ring-of-Health))
=>
(assert (item (name Vanguard)))
(assert (sendmessagehalt "Vanguard:Vitality-Booster+Ring-of-Health=Vanguard"))
(halt)
)

(defrule Veiled-Blade
(item (name Echo-Sabre))
(item (name Ghost-Scepter))
=>
(assert (item (name Veiled-Blade)))
(assert (sendmessagehalt "Veiled-Blade:Echo-Sabre+Ghost-Scepter=Veiled-Blade"))
(halt)
)

(defrule Warlord-s-Gauntlets
(item (name Battle-Fury))
(item (name Skull-Basher))
=>
(assert (item (name Warlord-s-Gauntlets)))
(assert (sendmessagehalt "Warlord-s-Gauntlets:Battle-Fury+Skull-Basher=Warlord-s-Gauntlets"))
(halt)
)

(defrule Wyrmhide-Shield
(item (name Dragon-Lance))
(item (name Vanguard))
=>
(assert (item (name Wyrmhide-Shield)))
(assert (sendmessagehalt "Wyrmhide-Shield:Dragon-Lance+Vanguard=Wyrmhide-Shield"))
(halt)
)

(defrule Xiphos-of-Agility
(item (name Crystalys))
(item (name Yasha))
=>
(assert (item (name Xiphos-of-Agility)))
(assert (sendmessagehalt "Xiphos-of-Agility:Crystalys+Yasha=Xiphos-of-Agility"))
(halt)
)

(defrule Zenith-Scroll
(item (name Aghanim-s-Scepter))
(item (name Refresher-Orb))
=>
(assert (item (name Zenith-Scroll)))
(assert (sendmessagehalt "Zenith-Scroll:Aghanim-s-Scepter+Refresher-Orb=Zenith-Scroll"))
(halt)
)

(defrule Kaya-Yasha-Sange
(item (name Kaya-and-Sange))
(item (name Yasha))
=>
(assert (item (name Kaya-Yasha-Sange)))
(assert (sendmessagehalt "Kaya-Yasha-Sange:Kaya-and-Sange+Yasha=Kaya-Yasha-Sange"))
(halt)
)

