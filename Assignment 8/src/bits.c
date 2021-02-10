#include "cache.h"
#include "bits.h"

int get_set (Cache *cache, address_type address) {
  // TODO:
  //  Extract the set bits from a 32-bit address.
  //

  int pushOff = (32- ((cache->set_bits)+(cache->block_bits)));

  //move left
  address = address << pushOff;
  address = address >>pushOff;

  address = address >> (cache->block_bits);

  return address;

}

int get_line (Cache *cache, address_type address) {
  // TODO:
  // Extract the tag bits from a 32-bit address.
  //
  int pushOff = ((cache->set_bits)+(cache->block_bits));
  address = address >> pushOff;
  return address;
}

int get_byte (Cache *cache, address_type address) {
  // TODO
  // Extract the block (byte index) bits from a 32-bit address.
  //
  int pushOff = 32 - (cache->block_bits);
  address = address <<pushOff;
  address = address >>pushOff;
  return address;
}

