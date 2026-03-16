"""
Simple Electronics Calculator
A collection of basic electronics calculations
"""

import math

def resistor_ohms_law(voltage=None, current=None, resistance=None):
    """
    Calculate missing value using Ohm's Law: V = I * R
    Provide any two parameters, leave the third as None
    """
    if voltage is not None and current is not None and resistance is None:
        return voltage / current  # R = V / I
    elif voltage is not None and resistance is not None and current is None:
        return voltage / resistance  # I = V / R
    elif current is not None and resistance is not None and voltage is None:
        return current * resistance  # V = I * R
    else:
        return "Error: Provide exactly two parameters"

def led_resistor_calculator(supply_voltage, led_voltage, led_current_ma):
    """
    Calculate resistor value for an LED
    supply_voltage: Power supply voltage (V)
    led_voltage: LED forward voltage (V)
    led_current_ma: Desired LED current (mA)
    """
    led_current_a = led_current_ma / 1000  # Convert mA to A
    resistor_value = (supply_voltage - led_voltage) / led_current_a
    
    # Standard resistor values (E12 series)
    standard_values = [10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82]
    
    # Find closest standard value
    closest = min(standard_values, key=lambda x: abs(x - resistor_value))
    
    return {
        'calculated_resistor': round(resistor_value, 1),
        'closest_standard': closest,
        'power_dissipation': round(resistor_value * led_current_a**2, 3)
    }

def capacitor_time_constant(resistance, capacitance):
    """
    Calculate RC time constant
    resistance: Ohms
    capacitance: Farads
    """
    tau = resistance * capacitance
    return {
        'time_constant': tau,
        'charge_percentage_1tau': 63.2,
        'charge_percentage_5tau': 99.3
    }

def voltage_divider(vin, r1, r2):
    """
    Calculate output voltage of a voltage divider
    vin: Input voltage
    r1: First resistor (top)
    r2: Second resistor (bottom)
    """
    vout = vin * (r2 / (r1 + r2))
    return round(vout, 2)

def parallel_resistance(*resistors):
    """
    Calculate total resistance for resistors in parallel
    Usage: parallel_resistance(100, 220, 330)
    """
    if not resistors:
        return 0
    
    reciprocal_sum = sum(1/r for r in resistors)
    total = 1 / reciprocal_sum
    return round(total, 2)

def series_resistance(*resistors):
    """
    Calculate total resistance for resistors in series
    Usage: series_resistance(100, 220, 330)
    """
    return sum(resistors)

def power_calculation(voltage=None, current=None, resistance=None):
    """
    Calculate power using P = V * I, P = V²/R, or P = I² * R
    Provide any two parameters
    """
    if voltage is not None and current is not None:
        return voltage * current
    elif voltage is not None and resistance is not None:
        return (voltage ** 2) / resistance
    elif current is not None and resistance is not None:
        return (current ** 2) * resistance
    else:
        return "Error: Provide two parameters"

def main():
    """Example usage of the electronics calculator"""
    print("=" * 50)
    print("ELECTRONICS CALCULATOR")
    print("=" * 50)
    
    # Example 1: Ohm's Law
    print("\n1. OHM'S LAW")
    print("-" * 20)
    v = 12  # 12V
    i = 0.5  # 500mA
    r = resistor_ohms_law(voltage=v, current=i)
    print(f"With V={v}V and I={i}A, R = {r}Ω")
    
    # Example 2: LED Resistor
    print("\n2. LED RESISTOR CALCULATOR")
    print("-" * 20)
    led = led_resistor_calculator(9, 2, 20)  # 9V supply, 2V LED, 20mA
    print(f"LED with 9V supply, 2V forward voltage, 20mA current:")
    print(f"  Calculated resistor: {led['calculated_resistor']}Ω")
    print(f"  Closest standard value: {led['closest_standard']}Ω")
    print(f"  Power dissipation: {led['power_dissipation']}W")
    
    # Example 3: Voltage Divider
    print("\n3. VOLTAGE DIVIDER")
    print("-" * 20)
    vout = voltage_divider(12, 1000, 2000)  # 12V in, 1kΩ and 2kΩ
    print(f"12V divided by 1kΩ and 2kΩ = {vout}V")
    
    # Example 4: Parallel Resistors
    print("\n4. PARALLEL RESISTORS")
    print("-" * 20)
    r_parallel = parallel_resistance(100, 220, 330)
    print(f"100Ω, 220Ω, and 330Ω in parallel = {r_parallel}Ω")
    
    # Example 5: Series Resistors
    print("\n5. SERIES RESISTORS")
    print("-" * 20)
    r_series = series_resistance(100, 220, 330)
    print(f"100Ω, 220Ω, and 330Ω in series = {r_series}Ω")
    
    # Example 6: RC Time Constant
    print("\n6. RC TIME CONSTANT")
    print("-" * 20)
    rc = capacitor_time_constant(1000, 0.001)  # 1kΩ, 1000µF
    print(f"With 1kΩ and 1000µF capacitor:")
    print(f"  Time constant (τ) = {rc['time_constant']} seconds")
    print(f"  At 1τ, capacitor charges to {rc['charge_percentage_1tau']}%")
    print(f"  At 5τ, capacitor charges to {rc['charge_percentage_5tau']}%")
    
    print("\n" + "=" * 50)

if __name__ == "__main__":
    main()
