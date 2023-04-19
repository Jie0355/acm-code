import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as ctrl
import matplotlib.pyplot as plt

# New Antecedent/Consequent objects hold universe variables and membership
# functions
stain = ctrl.Antecedent(np.arange(0, 101, 1), 'stain')
oil = ctrl.Antecedent(np.arange(0, 101, 1), 'oil')
washtime = ctrl.Consequent(np.arange(0, 120, 1), 'washtime')

# Auto-membership function population is possible with .automf(3, 5, or 7)
stain.automf(3, variable_type='quant')
oil.automf(3, variable_type='quant')

# Custom membership functions can be built interactively with a familiar,
# Pythonic API

washtime['VS'] = fuzz.trimf(washtime.universe, [0, 0, 20])
washtime['S'] = fuzz.trimf(washtime.universe, [0, 20, 50])
washtime['M'] = fuzz.trimf(washtime.universe, [20, 50, 70])
washtime['L'] = fuzz.trimf(washtime.universe, [50, 70, 100])
washtime['VL'] = fuzz.trimf(washtime.universe, [70, 100, 120])

"""
To help understand what the membership looks like, use the ``view`` methods.
These return the matplotlib `Figure` and `Axis` objects. They are persistent
as written in Jupyter notebooks; other environments may require a `plt.show()`
command after each `.view()`.
"""

# You can see how these look with .view()
stain['average'].view()
plt.show()

oil.view()
plt.show()

washtime.view()
plt.show()
"""
.. image:: PLOT2RST.current_figure
Fuzzy rules
-----------
Now, to make these triangles useful, we define the *fuzzy relationship*
between input and output variables.
"""
# low = SD or NG；average = MD or MG；high=LD or LG
rule1 = ctrl.Rule(stain['low'] & oil['low'], washtime['VS'])
rule2 = ctrl.Rule(stain['low'] & oil['average'], washtime['M'])
rule3 = ctrl.Rule(stain['low'] & oil['high'], washtime['L'])
rule4 = ctrl.Rule(stain['average'] & oil['low'], washtime['S'])
rule5 = ctrl.Rule(stain['average'] & oil['average'], washtime['M'])
rule6 = ctrl.Rule(stain['average'] & oil['high'], washtime['L'])
rule7 = ctrl.Rule(stain['high'] & oil['low'], washtime['M'])
rule8 = ctrl.Rule(stain['high'] & oil['average'], washtime['L'])
rule9 = ctrl.Rule(stain['high'] & oil['high'], washtime['VL'])





"""
.. image:: PLOT2RST.current_figure
Control System Creation and Simulation
---------------------------------------
Now that we have our rules defined, we can simply create a control system
via:
"""

washtimeping_ctrl = ctrl.ControlSystem([rule1, rule2, rule3, rule4, rule5, rule6, rule7, rule8, rule9])

"""
In order to simulate this control system, we will create a
``ControlSystemSimulation``.  Think of this object representing our controller
applied to a specific set of circumstances.  For washtimeping, this might be washtimeping
Sharon at the local brew-pub.  We would create another
``ControlSystemSimulation`` when we're trying to apply our ``washtimeping_ctrl``
for Travis at the cafe because the inputs would be different.
"""

washtimeping = ctrl.ControlSystemSimulation(washtimeping_ctrl)

"""
We can now simulate our control system by simply specifying the inputs
and calling the ``compute`` method.  
"""
# Pass inputs to the ControlSystem using Antecedent labels with Pythonic API
# Note: if you like passing many inputs all at once, use .inputs(dict_of_data)
washtimeping.input['stain'] = 2
washtimeping.input['oil'] = 2

# Crunch the numbers
washtimeping.compute()

"""
Once computed, we can view the result as well as visualize it.
"""
print(washtimeping.output['washtime'])
washtime.view(sim=washtimeping)
plt.show()
