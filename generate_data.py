import random
import struct
import os

script_dir = os.path.dirname(os.path.abspath(__file__))
output_path = os.path.join(script_dir, 'data.bin')

# Generate 1000 random integers between 0 and 999
data = [random.randint(0, 999) for _ in range(1000)]

# Pack them as 1000 'int' (i) values
packed_data = struct.pack(f'{len(data)}i', *data)

with open(output_path, 'wb') as f:
    f.write(packed_data)

print(f"Created {output_path} with 1000 integers.")