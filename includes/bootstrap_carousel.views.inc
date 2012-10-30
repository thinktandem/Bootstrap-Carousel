<?php

/**
 * Defines the carousel style. Implements hook_views_plugins().
 * 
 */
function bootstrap_carousel_views_plugins() {
  $plugins['style']['bootstrap_carousel'] = array(
    'title' => t('Bootstrap Carousel'),
    'help' => t('Display each row as a carousel slide.'),
    'handler' => 'views_plugin_style_bootstrap_carousel',
    'path' => drupal_get_path('module', 'bootstrap_carousel') . '/includes',
    'theme' => 'views_view_bootstrap_carousel',
    'theme path' => drupal_get_path('module', 'bootstrap_carousel') . '/includes',
    'uses row plugin' => TRUE,
    'uses row class' => TRUE,
    'uses options' => TRUE,
    'type' => 'normal',
	);

	return $plugins;
}

function template_preprocess_views_view_bootstrap_carousel(&$vars){
	//Add bootstrap carousel js
	if($bootstrap_path = libraries_get_path('bootstrap')){	
	  drupal_add_js($bootstrap_path . '/js/bootstrap-carousel.js');
	}
	$carousel_path = drupal_get_path('module', 'bootstrap_carousel');
	drupal_add_css($carousel_path . '/includes/bootstrap-carousel.css');

  $vars['carousel_id'] = $vars['options']['bootstrap_carousel_id'];
  $vars['bootstrap_container'] = $vars['options']['bootstrap_container'];
	template_preprocess_views_view_unformatted($vars);
}
