<?php

/**
 * @file
 *  Template file showing all the available languages for each domain.
 *
 *  The following variables are available:
 *  - $domains: An array with the available domains, keyed by the domain name.
 *  Each value of the array is an associtive array with to following structure:
 *    - name: The name of the domain.
 *    - machine_name: The machine name of the domain.
 *    - path: The path of the domain.
 *    - languages: An array with language objects, keyed by the language code.
 */

print '<div>';
foreach ($domains as $machine_name => $domain) {
  print '<div class="domain-language-group">';
    $class = "language-group-title " . $domain['machine_name'];
    print '<div class="'. $class .'">' . check_plain($domain['name']) . '</div>';
    foreach ($domain['languages'] as $lang) {
      print '<div class="language-name">' . l($lang->native, $domain['path'] . $lang->prefix) . '</div>';
    }
  print '</div>';
}
print '</div>';
