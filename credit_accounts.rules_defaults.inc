<?php
/**
 * @file
 * credit_accounts.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function credit_accounts_default_rules_configuration() {
  $items = array();
  $items['commerce_payment_credit_accounts'] = entity_import('rules_config', '{ "commerce_payment_credit_accounts" : {
    "LABEL" : "Credit account",
    "PLUGIN" : "reaction rule",
    "OWNER" : "rules",
    "TAGS" : [ "Commerce Payment" ],
    "REQUIRES" : [ "rules", "commerce_payment" ],
    "ON" : { "commerce_payment_methods" : [] },
    "IF" : [
      { "user_has_role" : {
          "account" : [ "site:current-user" ],
          "roles" : { "value" : { "3" : "3" } },
          "operation" : "OR"
        }
      },
      { "commerce_payment_order_balance_comparison" : {
          "commerce_order" : [ "commerce_order" ],
          "operator" : "\u003E",
          "value" : "0"
        }
      }
    ],
    "DO" : [
      { "commerce_payment_enable_credit_accounts" : {
          "commerce_order" : [ "commerce-order" ],
          "payment_method" : "credit_accounts"
        }
      }
    ]
  }
}');
  return $items;
}
