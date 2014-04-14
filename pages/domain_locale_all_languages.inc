<?php

/**
 * @file
 *  Default page for "All languages".
 */

$page = new stdClass();
$page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
$page->api_version = 1;
$page->name = 'all_languages';
$page->task = 'page';
$page->admin_title = 'All languages';
$page->admin_description = 'A page that shows all available languages.';
$page->path = 'all_languages';
$page->access = array();
$page->menu = array();
$page->arguments = array();
$page->conf = array(
  'admin_paths' => FALSE,
);
$page->default_handlers = array();
$handler = new stdClass();
$handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
$handler->api_version = 1;
$handler->name = 'page_all_languages_panel_context';
$handler->task = 'page';
$handler->subtask = 'all_languages';
$handler->handler = 'panel_context';
$handler->weight = 0;
$handler->conf = array(
  'title' => 'Panel',
  'no_blocks' => 0,
  'pipeline' => 'standard',
  'body_classes_to_remove' => '',
  'body_classes_to_add' => '',
  'css_id' => '',
  'css' => '',
  'contexts' => array(),
  'relationships' => array(),
);
$display = new panels_display();
$display->layout = 'onecol';
$display->layout_settings = array();
$display->panel_settings = array(
  'style_settings' => array(
    'default' => NULL,
    'header' => NULL,
    'top_slider' => NULL,
    'brands' => NULL,
    'map' => NULL,
    'awards' => NULL,
    'employees' => NULL,
    'follow_us' => NULL,
    'bottom_slider' => NULL,
    'middle' => NULL,
  ),
);
$display->cache = array();
$display->title = 'Select your country & language';
$display->uuid = 'cb8c54ba-e7da-f974-f988-1a51bc7288cd';
$display->content = array();
$display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-852b7145-5b0e-eba4-e161-6a7824895272';
  $pane->panel = 'middle';
  $pane->type = 'domain_locale_all_languages';
  $pane->subtype = 'domain_locale_all_languages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '852b7145-5b0e-eba4-e161-6a7824895272';
  $display->content['new-852b7145-5b0e-eba4-e161-6a7824895272'] = $pane;
  $display->panels['middle'][0] = 'new-852b7145-5b0e-eba4-e161-6a7824895272';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$handler->conf['display'] = $display;
$page->default_handlers[$handler->name] = $handler;
