<?php

/**
 * Implements of hook_rules_condition_info().
 */
function multistep_adl_rules_condition_info() {
  return array(
    'multistep_adl_is_complete' => array(
      'label' => t('Content is complete'),
      'group' => t('Multistep ADL'),
      'parameter' => array(
        'node' => array(
          'label' => t('Content'),
          'type' => 'node',
        ),
      ),
    ),
    'multistep_adl_will_complete' => array(
      'label' => t('Content will complete'),
      'group' => t('Multistep ADL'),
      'parameter' => array(
        'node' => array(
          'label' => t('Content'),
          'type' => 'node',
        ),
      ),
    ),
  );
}