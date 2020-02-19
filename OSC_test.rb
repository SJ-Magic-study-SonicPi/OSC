
use_osc "127.0.0.1", 12345

live_loop :foo do
  use_real_time
  a, b, c = sync "/osc/trigger"
  synth :prophet, note: a, cutoff: b, sustain: c
  
  osc "/Hello/World", 102
end
