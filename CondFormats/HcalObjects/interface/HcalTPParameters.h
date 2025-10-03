#ifndef CondFormatsHcalObjectsHcalTPParameters_h
#define CondFormatsHcalObjectsHcalTPParameters_h

#include "CondFormats/Serialization/interface/Serializable.h"

#include <vector>
#include <algorithm>
#include <cstdint>

class HcalTPParameters {
public:
  HcalTPParameters();
  ~HcalTPParameters();

  // Load a new entry
  void loadObject(int version, int adcCut, uint64_t tdcMask, uint32_t tbits, uint32_t auxi1, int auxi2);

  /// get FineGrain Algorithm Version for HBHE
  int getFGVersionHBHE() const { return version_; }
  /// get ADC threshold fof TDC mask of HF
  int getADCThresholdHF() const { return adcCut_; }
  /// get TDC mask for HF
  uint64_t getTDCMaskHF() const { return tdcMask_; }
  /// get Self Trigger bits
  uint32_t getHFTriggerInfo() const { return tbits_; }
  /// get Axiliary words
  uint32_t getAuxi1() const { return auxi1_; }
  int getAuxi2() const { return auxi2_; }
  /// get low and high HF MinBias FG thresholds
  uint8_t getHFFGThresholdLow() const { return (auxi1_ >> lowFGthres_shift) & lowFGthres_mask; }
  uint8_t getHFFGThresholdHigh() const { return (auxi1_ >> highFGthres_shift) & highFGthres_mask; }

private:
  int version_;
  int adcCut_;
  uint64_t tdcMask_;
  uint32_t tbits_;
  uint32_t auxi1_;
  int auxi2_;

  static const unsigned int lowFGthres_shift = 0;
  static const unsigned int lowFGthres_mask = 0xFF;
  static const unsigned int highFGthres_shift = 8;
  static const unsigned int highFGthres_mask = 0xFF;

  COND_SERIALIZABLE;
};

#endif
