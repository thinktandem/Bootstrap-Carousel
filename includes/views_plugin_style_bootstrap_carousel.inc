<?php

class views_plugin_style_bootstrap_carousel extends views_plugin_style {
  function option(&$options) {
    parent::options($options);
    $options['bootstrap_container'] = array('default' => 'hero-unit');
    $options['bootstrap_carousel_id'] = array('default' => 'myCarousel');
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $bootstrap_containers = array(
    	'hero-unit' => t('Hero Unit'),
    	'well' => t('Well'),
    	'none' => t('No Container')
    );

   	$form['bootstrap_container'] = array(
      '#type' => 'radios',
      '#title' => t('Bootstrap Container'),
      '#default_value' => $this->options['bootstrap_container'],
      '#options' => $bootstrap_containers,
      '#required' => TRUE,
   	);

   	$form['bootstrap_carousel_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Carousel ID'),
      '#description' => t('Bootstrap carousels respond to a unique ID; if you have multiple carousels on the same page, you will need unique ids.'),
      '#default_value' => $this->options['bootstrap_carousel_id'],
      '#required' => TRUE,
   	); 
  }
}
