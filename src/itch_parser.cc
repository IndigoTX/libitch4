#include <itch_parser.hh>

namespace Itch {
  Dispatch_error Message::dispatch(Message_switch &message_switch) const {
    switch(message_type()) {
    case MT_TIMESTAMP:
      return message_switch.handle(message_types.timestamp_message);
    case MT_SEM:
      return message_switch.handle(message_types.system_event_message);
    case MT_SDM:
      return message_switch.handle(message_types.stock_directory_message);
    case MT_STAM:
      return message_switch.handle(message_types.stock_trading_action_message);
    case MT_RSSSPTM:
      return message_switch.handle(message_types.reg_sho_message);
    case MT_MPPM:
      return message_switch.handle(message_types.market_participant_message);
    case MT_AONMM:
      return message_switch.handle(message_types.add_order_no_mpid_message);
    case MT_AOWMM:
      return message_switch.handle(message_types.add_order_with_mpid_message);
    case MT_OEM:
      return message_switch.handle(message_types.order_executed_message);
    case MT_OEWPM:
      return message_switch.handle(message_types.order_executed_with_price_message);
    case MT_OCM:
      return message_switch.handle(message_types.order_cancel_message);
    case MT_ODM:
      return message_switch.handle(message_types.order_delete_message);
    case MT_ORM:
      return message_switch.handle(message_types.order_replace_message);
    case MT_TRADEM:
      return message_switch.handle(message_types.trade_message);
    case MT_CROSSTRADEM:
      return message_switch.handle(message_types.cross_trade_message);
    case MT_BROKENTRADEM:
      return message_switch.handle(message_types.broken_trade_message);
    case MT_NOIIM:
      return message_switch.handle(message_types.net_order_imbalance_indicator_message);
    default:
      return D_UNKNOWN_MESSAGE;
    }
  }
}
