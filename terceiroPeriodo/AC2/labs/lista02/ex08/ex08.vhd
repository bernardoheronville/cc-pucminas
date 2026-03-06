library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux41 is
Port (
    a, b, c, d : in STD_LOGIC;
    s1, s0 : in STD_LOGIC;
    y : out STD_LOGIC
);
end mux41;

architecture Behavioral of mux41 is
begin
    y <= a when (s1 = '0' and s0 = '0') else
         b when (s1 = '0' and s0 = '1') else
         c when (s1 = '1' and s0 = '0') else
         d;
end Behavioral;