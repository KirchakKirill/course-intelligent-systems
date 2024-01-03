
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
                        
(item (name  f2))

(item (name f3))

=>

(assert (item (name f13)))
(assert (sendmessagehalt "f13: gel,wood->torch"))
(halt)
)
(item (name  f13))

(item (name f5))

=>

(assert (item (name f17)))
(assert (sendmessagehalt "f17: torch,amethyst->purple torch"))
(halt)
)
(item (name  f18))

(item (name  f4))

=>

(assert (item (name f16)))
(assert (sendmessagehalt "f16: heat,iron ore->iron bar"))
(halt)
)
(item (name  f20))

(item (name  f21))

=>

(assert (item (name  f19)))
(assert (sendmessagehalt " f19: golden bar,ruby -> ruby staff"))
(halt)
)
(item (name  f18))

(item (name  f20))

=>

(assert (item (name  f21)))
(assert (sendmessagehalt " f21: heat, golden ore->golden bar"))
(halt)
)
(item (name  f3))

=>

(assert (item (name  f22)))
(assert (sendmessagehalt " f22: wood->wooden armor"))
(halt)
)
(item (name  f3))

=>

(assert (item (name  f23)))
(assert (sendmessagehalt " f23: wood->wooden door"))
(halt)
)
(item (name  f3))

(item (name  f16))

=>

(assert (item (name  f24)))
(assert (sendmessagehalt " f24: wood,iron bar->chest"))
(halt)
)
(item (name  f18))

(item (name  f16))

=>

(assert (item (name  f4)))
(assert (sendmessagehalt " f4: heat, iron bar -> iron ore"))
(halt)
)
(item (name  f29))

(item (name f30))

=>

(assert (item (name f39)))
(assert (sendmessagehalt "f39: water, bottle -> bottle with water"))
(halt)
)
(item (name  f29))

(item (name f2))

(item (name f31))

=>

(assert (item (name  f25)))
(assert (sendmessagehalt " f25: bottle,gel,mushroom->heal potion"))
(halt)
)
(item (name  f25))

(item (name f32))

=>

(assert (item (name  f26)))
(assert (sendmessagehalt " f26: heal potion, glowing myshroom -> heal potion+"))
(halt)
)
(item (name  f39))

(item (name  f33))

(item (name f34))

=>

(assert (item (name f27)))
(assert (sendmessagehalt "f27: bottle with water, pixie dust, crystal shard->heal potion++"))
(halt)
)
(item (name  f26))

(item (name f35))

(item (name f36))

(item (name f37))

(item (name f38))

=>

(assert (item (name f28)))
(assert (sendmessagehalt "f28: heal potion++,pixie dust,crystal shard,nebula,solar,stardust,vortex->heal potion+++"))
(halt)
)
(item (name  f25))

(item (name f26))

(item (name f27))

(item (name f28))

=>

(assert (item (name  f40)))
(assert (sendmessagehalt " f40: heal potion, heal potion+, heal potion++, heal potion+++->heal potion++++"))
(halt)
)
(item (name  f41))

=>

(assert (item (name f42)))
(assert (sendmessagehalt "f42: a1->a2"))
(halt)
)
(item (name  f42))

=>

(assert (item (name f43)))
(assert (sendmessagehalt "f43: a2->a3"))
(halt)
)
(item (name  f43))

=>

(assert (item (name f41)))
(assert (sendmessagehalt "f41: a3->a1"))
(halt)
)
