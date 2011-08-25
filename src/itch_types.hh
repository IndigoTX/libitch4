#ifndef ITCH_TYPES_HH
#define ITCH_TYPES_HH

#include <cstdint>

#include <fixed_array.hh>

namespace Itch {
  enum Message_types {
    MT_TIMESTAMP = 'T',
    /* System Event Message */
    MT_SEM = 'S',
    /* Stock Directory Message */
    MT_SDM = 'R',
    /* Stock Trading Action Message */
    MT_STAM = 'H',
    /* Reg SHO Short Sale Price Test Restricted Indicator Message */
    MT_RSSSPTM = 'Y',
    /* Market Participant Position Message */
    MT_MPPM = 'L',
    /* Add Order No MPID Message */
    MT_AONMM = 'A',
    /* Add Order With MPID Message */
    MT_AOWMM = 'F',
    /* Order Executed Message */
    MT_OEM = 'E',
    /* Order Executed With Price Message */
    MT_OEWPM = 'C',
    /* Order Cancel Message */
    MT_OCM = 'X',
    /* Order Delete Message */
    MT_ODM = 'D',
    /* Order Replace Message */
    MT_ORM = 'U',
    /* Trade Message */
    MT_TRADEM = 'P',
    /* Cross Trade Message */
    MT_CROSSTRADEM = 'Q',
    /* Broken Trade Message */
    MT_BROKENTRADEM = 'B',
    /* Net Order Imbalance Indicator Message */
    MT_NOIIM = 'I'
  };

  
  
  enum System_event_code {
    SEC_START_MESSAGES = 'O',
    SEC_START_SYSTEM = 'S',
    SEC_START_MARKET = 'Q',
    SEC_END_MARKET = 'M',
    SEC_END_SYSTEM = 'E',
    SEC_END_EMSSAGES = 'C',

    SEC_EMC_HALT = 'A',
    SEC_EMC_QUOTE_ONLY = 'R',
    SEC_EMC_RESUME = 'B'
  };

  enum Market_category {
    MC_NYSE = 'N',
    MC_NYSE_AMEX = 'A',
    MC_NYSE_ARCA = 'P',
    MC_NASDAQ_GSM = 'Q',
    MC_NASDAQ_GM = 'G',
    MC_NASDAQ_CM = 'S'
  };

  enum Financial_status_indicator {
    FSI_DEFICIENT = 'D',
    FSI_DELINQUENT = 'E',
    FSI_BANKRUPT = 'Q',
    FSI_SUSPENDED = 'S',
    FSI_DEFICIENT_BANKRUPT = 'G',
    FSI_DEFICIENT_DELINQUIENT = 'H',
    FSI_DELINQUIENT_BANKRUPT = 'J',
    FSI_DEFICIENT_DELINQUIENT_BANKRUPT = 'K',

    FSI_COMPLIANT = ' '
  };

  enum Round_lots_only {
    RLO_Y = 'Y',
    RLO_N = 'N'
  };

  enum Trading_state {
    TS_HALTED_ALL = 'H',
    TS_HALTED_NASDAQ = 'V',
    TS_QUOTES_ALL = 'Q',
    TS_QUOTES_NASDAQ = 'R',
    TS_TRADING_NASDAQ = 'T'
  };

  enum Reg_sho_action {
    RSA_NO_PRICE_TEST = '0',
    RSA_START = '1',
    RSA_REMAIN = '2'
  };

  enum Primary_market_maker {
    PMM_Y = 'Y',
    PMM_N = 'N'
  };

  enum Market_maker_mode {
    MMM_NORMAL = 'N',
    MMM_PASSIVE = 'P',
    MMM_SYNDICATE = 'S',
    MMM_PRE_SYNDICATE = 'R',
    MMM_PENALTY = 'L'
  };

  enum Market_participant_state {
    MPS_ACTIVE = 'A',
    MPS_EXCUSED = 'E',
    MPS_WITHDRAWN = 'W',
    MPS_SUSPENDED = 'S',
    MPS_DELETED = 'D'
  };

  enum Buy_sell_indicator {
    BSI_BUY = 'B',
    BSI_SELL = 'S'
  };

  enum Printable {
    P_PRINTABLE = 'Y',
    P_NON_PRINTABLE = 'N'
  };

  enum Cross_type {
    CT_OPENING_CROSS = 'O',
    CT_CLOSING_CROSS = 'C',
    CT_HALTED = 'H',
    CT_INTRADAY = 'I'
  };

  enum Imbalance_direction {
    ID_BUY = 'B',
    ID_SELL = 'S',
    ID_NO_IMBALANCE = 'N',
    ID_INSUFFICIENT = 'O'
  };

  enum Price_variation_indicator {
    PVI_LESS_1 = 'L',
    PVI_1_199 = '1',
    PVI_2_299 = '2',
    PVI_3_399 = '3',
    PVI_4_499 = '4',
    PVI_5_599 = '5',
    PVI_6_699 = '6',
    PVI_7_799 = '7',
    PVI_8_899 = '8',
    PVI_9_999 = '9',
    PVI_10_1999 = 'A',
    PVI_20_2999 = 'B',
    PVI_30_ABOVE = 'C',
    PVI_NO_CALCUALTE = ' '
  };
  
  typedef Fixed_array<unsigned char, 8> Stock_symbol;

  /*
   * I am using the C++ type guaranteed to be able to hold these values even if the actual
   * size may be smaller
   */

  typedef long Seconds;
  typedef long Nanoseconds;

  struct Timestamp { Seconds seconds; Nanoseconds nanoseconds; };

  typedef long Round_lot_size;

  typedef Fixed_array<unsigned char, 4> Mpid;

  typedef std::uint64_t Order_reference_number;

  typedef std::uint64_t Shares;

  /* Temporary until I implement a type for a price */
  typedef long Price;

  typedef Fixed_array<unsigned char, 4> Attribution;

  typedef std::uint64_t Match_number;

  typedef std::uint64_t Imbalance;
  
}

#endif
