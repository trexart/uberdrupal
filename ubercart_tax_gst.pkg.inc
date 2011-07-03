<?php

/**
 * @file
 * Define the Australian GST support package for enabling GST as default tax
 */


/**
 * Implementation of hook_pkg_info().
 */
function ubercart_tax_gst_pkg_info() {

  return array(
    'title' => t('Australian GST support'),
    'description' => t('This package installs GST as the default tax implementation.'),
    'modules' => array('uc_payment', 'uc_taxes', 'uc_vat'),
  );
}

/**
 * Implementation of hook_pkg_postinstall().
 */
function ubercart_tax_gst_pkg_postinstall() {
  require_once drupal_get_path('module', 'ca') .'/ca.admin.inc';
  
  $rateArray = array(
      'id' => '',
      'name' => 'GST',
      'rate' => '.1',
      'taxed_product_types' => array('product'),
      'taxed_line_items' => array(),
      'weight' => 0,
      'shippable' => 0,
    );
  $rate = uc_taxes_rate_save((object) $rateArray);
    
  drupal_set_message(t('Tax rate %name saved.', array('%name' => $rate->name)));

  variable_set('uc_vat_name', 'GST');
  variable_set('uc_vat_suffix_tax', 1);
  variable_set('uc_vat_list_price_inclusive', 1);
  variable_set('uc_vat_cost_inclusive', 1);
  variable_set('uc_vat_sell_price_inclusive', 1);
  variable_set('uc_vat_show_cart_vat', 1);
  variable_set('uc_vat_hide_checkout_exclusive', 1);
  
  // set predicate conditions
  $pid = 'uc_taxes_'. $rate->id;
  $conditions = array(
                  'operator'=>'AND', 
                  'conditions'=>array(
                                  0=>array(
                                      'operator'=>'AND', 
                                      'conditions'=>array(
                                                      0=>array(
                                                          'name'=>'uc_order_condition_delivery_country',
                                                          'title'=>'Check an order\'s shipping country',
                                                          'argument_map'=>array('order'=>'order'),
                                                          'settings'=>array('negate'=>0, 'countries'=>array(36=>'36')),
                                                       ),
                                                     ),
                                  ),
                               ),
               );
  ca_conditions_form_update_conditions($pid, $conditions);
}
